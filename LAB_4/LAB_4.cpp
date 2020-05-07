TreeElement* maximum(TreeElement* el)
{
	if (el->right == NULL)
		return el;
	else
		return maximum(el->right);
}



















TreeElement* udal_hecnhet(TreeElement* root) //Функция удаления четных листьев бинарного дерева
{
	if (!root)
		return 0;
	if (!root->left && !root->right && !(root->value % 2))
	{
		delete(root);
		return 0;
	}
	root->left = udal_hecnhet(root->left);
	root->right = udal_hecnhet(root->right);
	return root;
}
int treenode_max(const TreeElement* p) {
	if (p == nullptr)
		return 0;
	while (p->right != nullptr)
		p = p->right;
	return p->value;
}
