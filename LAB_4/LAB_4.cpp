
#include"stdafx.h"
#include <iostream>
using namespace std;
struct TreeElement
{
	int value;
	TreeElement* right;
	TreeElement* left;
	TreeElement()
	{
		value = -1;
		right = NULL;
		left = NULL;
	}
};
struct ListElement
{
	int value;
	ListElement* next;

};
void Input(TreeElement*& el, int v)
{
	if (el == NULL)
	{
		el = new TreeElement();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}
void Output(TreeElement* el)
{
	if (el != NULL)
	{
		Output(el->left);
		cout << el->value << " ";
		Output(el->right);
	}

}
void Detach(TreeElement* root, TreeElement* el)
{
	if (root == NULL || el == NULL) { return; }
	else if (root->left == el) { root->left = NULL; }
	else if (root->right == el) { root->right = NULL; }
	{
		Detach(root->left, el);
		Detach(root->right, el);
	}
}
void Remove(TreeElement* el)
{
	if (el)
	{
		Remove(el->left);
		Remove(el->right);
		delete el;
	}
}
TreeElement* Find(TreeElement* el, int v)
{
	TreeElement* result = NULL;
	if (el == NULL) { result = NULL; }
	else if (el->value == v) { result = el; }
	else
	{
		result = Find(el->left, v);
		if (result == NULL) { result = Find(el->right, v); }
	}
	return result;
}
void List(ListElement*& first, TreeElement* el, ListElement*& elem)
{
	if (el)
	{
		List(first, el->left, elem);
		ListElement* to = new ListElement();
		to->value = el->value;
		if (elem == NULL)
		{
			first = to;
			elem = to;
		}
		else
		{
			elem->next = to;
			elem = to;
		}
		List(first, el->right, elem);
	}
}

void OutputList(ListElement* l)
{
	while (l)
	{
		cout << l->value << " ";
		l = l->next;
	}
	cout << endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	TreeElement* root = NULL;
	ListElement* num = NULL;
	int N = 0, el;
	cout << "Введите количество чисел " << endl;
	cin >> N;
	cout << "Введите числа " << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> el;
		Input(root, el);
	}
	Output(root);
	cout << endl;
	int n;
	cout << "Для удаления поддерева введите число" << endl;
	cin >> n;
	TreeElement* e = Find(root, n);
	Detach(root, e);
	Remove(e);
	Output(root);
	cout << endl;
	cout << "Список ";
	ListElement* begin = NULL;
	List(num, root, begin);
	OutputList(num);
	return 0;


}