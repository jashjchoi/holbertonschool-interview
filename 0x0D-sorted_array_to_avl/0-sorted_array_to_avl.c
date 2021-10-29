#include "binary_trees.h"
/**
 * create_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: New Node or NULL if fail
 */
binary_tree_t *create_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	return (new_node);
}

/**
 * avl_tree - recursive function to build a tree
 * @array: pointer to the first element of the array to be converted
 * @start: lower element
 * @end: upper element
 * Return: pointer to the root of an AVL Node, or NULL
 **/
avl_t *avl_tree(int *array, int start, int end)
{
	int mid;
	avl_t *parent;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	parent = create_tree_node(NULL, array[mid]);
	if (!parent)
		return (NULL);

	parent->left = avl_tree(array, start, mid - 1);
	parent->right = avl_tree(array, mid + 1, end);

	if (parent->left)
		parent->left->parent = parent;
	if (parent->right)
		parent->right->parent = parent;
	return (parent);
}
/**
 * sorted_array_to_avl - builds a tree out of sorted array
 * @array: pointer to the first element of the array to be converted
 * @size:  number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size < 1)
		return (NULL);

	root = avl_tree(array, 0, size - 1);
	return (root);
}
