#include "libc/memory.h"
#include "libc/types.h"
#include "libc/null.h"

#define FREE ('F' + ('R' << 8) + ('E' << 16) + ('E' << 24))
#define USED ('U' + ('S' << 8) + ('E' << 16) + ('D' << 24))

/** The header before memory blocks.
  * The actual memory being handed out follows the header.
  */
struct memblk {
	int type;	/**< Either FREE or USED values otherwise an error */
	int size;	/**< The number of bytes in the block.*/
	struct memblk *next;	/**< Pointer to the next block,
				  or NULL if this is the last block. */
	struct memblk *prev;	/**< Pointer to the previous block,
				  or NULL if this is the first block. */
};

struct memblk *baseaddr;

void *calloc(size_t num, size_t size)
{
	void *mem;
	size_t total;

	total = size * num;
	/* Check for an overflow */
	if (num == 0 || total / num != size) return NULL;

	mem = malloc(total);
	if (!mem) return NULL;

	return memset(mem, 0, total);
}


void *malloc(size_t size)
{
	struct memblk *b;

	/* Find an empty block with enough free space. */
	b = find_block(size);

	/* If no block was found return null*/
	if (!b) return NULL;
	
	/* If there's more space in the block than needed, split it into two.*/
	/* Make sure there's enough space for a new header as well! */
	if (b->size > (size + sizeof(*b))) {
		split_block(b, size);
	}

	/* Mark as allocated. */
	b->type = USED;

	/* Return the memory after the header. */
	return b + 1;
}


void free(void *ptr)
{
	struct memblk *b = ptr;

	/* Move back from the memory to the header. */
	b = b - 1;

	/* Mark the block as free. */
	b->type = FREE;

	/* If the following block is also a free block, merge it. */
	/* This should avoid fragmentation. */
	if (b->next && b->next->type == FREE) {
		merge_block(b);
	}

	/* If the previous block is also a free block, merge it. */
	if (b->prev && b->prev->type == FREE) {
		b = b->prev;
		merge_block(b);
	}
}





/* Setup the memory manager. */
void memory_init(void *base, int size)
{
	/* Setup a free memory block filling the entire memory area. */
	baseaddr = base;

	baseaddr->type = FREE;
	baseaddr->size = size - sizeof(*baseaddr);
	baseaddr->next = 0;
	baseaddr->prev = 0;
}


/* Split a memory block in two. */
void split_block(struct memblk *b, int split_point)
{
	char *newaddr;
	struct memblk *nb;

	if (!b) return;
	if (b->size <= sizeof(*b)) return;

	/* Locate the next block's header in an offset within the 
	 * current block. */
	newaddr = (char*)b + sizeof(*b) + split_point;
	nb = newaddr;

	nb->type = b->type;

	/* Update the sizes.
	 * The current block is now the size of the split point.
	 * The new block's size is the remaining space minus it's header.
	 */
	nb->size = b->size - split_point - sizeof(*b);
	b->size = split_point;

	/* Now update the linked list.
	 * It goes from this:
	 *   b <--> b->next
	 * To this:
	 *   b <--> nb <--> b->next
	 */
	if (b->next) {
		b->next->prev = nb;
	}

	nb->next = b->next;
	nb->prev = b;
	b->next = nb;
}


/* Merge a memory block with the next one. */
void merge_block(struct memblk *b)
{
	struct memblk *mb;

	if (!b) return;
	if (!b->next) return;

	mb = b->next;

	/* Add the two sizes together, including the header of the second,
	 * this'll become part of the first block. */
	b->size += b->next->size + sizeof(*b);

	/* Now update the linked list.
	 * It goes from this:
	 *   b <--> mb <--> mb->next
	 * To this:
	 *   b <--> mb->next
	 */
	if (mb->next) {
		mb->next->prev = b;
	}
	b->next = mb->next;
}


/* Find a free block of memory the same size or larger than a given size. 
 * NULL is return is none are available */
struct memblk *find_block(int min_size)
{
	struct memblk *b = baseaddr;

	/* Search though all memory blocks from the start. */
	while (b) {
		/* Check for heap corruption while searching. */
		if (b->type != FREE && b->type != USED) {
			os_print_string("Heap corrupted.");
			_Exit();
		}

		/* Return the first free block that's large enough. */
		if (b->type == FREE && b->size >= min_size) {
			return b;
		}

		b = b->next;
	}

	/* No block was found. */
	return NULL;
}

