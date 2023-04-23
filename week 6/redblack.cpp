#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

// Estrutura para representar um no da arvore
typedef struct node
{
  bool isBlack;              // No preto?
  bool isNull;               // No nulo?
  int value;                 // Valor
  struct node *left, *right; // Filhos
} *Node;

// Criar um no a partir de um numero
Node mkNode(int v)
{
  Node aux = (Node)malloc(sizeof(struct node));
  aux->isNull = (v == 0);
  aux->isBlack = (v >= 0);
  aux->value = abs(v);
  return aux;
}

// Ler input em preorder
Node readPreOrder()
{
  int v;
  cin >> v;
  Node aux = mkNode(v);
  if (v != 0)
  {
    aux->left = readPreOrder();
    aux->right = readPreOrder();
  }
  return aux;
}

// Menor valor da arvore
int minimum(Node t)
{
  if (t->isNull)
    return INT_MAX;
  int minLeft = minimum(t->left);
  int minRight = minimum(t->right);
  return min(t->value, min(minLeft, minRight));
}

// Maior valor da arvore
int maximum(Node t)
{
  if (t->isNull)
    return INT_MIN;
  int maxLeft = maximum(t->left);
  int maxRight = maximum(t->right);
  return max(t->value, max(maxLeft, maxRight));
}

// Quantidade de nos (internos)
int size(Node t)
{
  if (t->isNull)
    return 0;
  return 1 + size(t->left) + size(t->right);
}

bool null(Node t)
{
  if (t->isNull && !t->isBlack)
    return false;
  else
    return true;
  return null(t->left) && null(t->right);
}

bool reds(Node t)
{
  if (t->isNull)
    return true;
  if (!t->isBlack && (!t->left->isBlack || !t->right->isBlack))
    return false;
  return reds(t->left) && reds(t->right);
}

int smth(Node t)
{
  if (t->isNull)
    return 1;
  if (t->isBlack)
    return 1 + smth(t->left);
  return smth(t->left);
}

bool caminho(Node t, int c)
{
  if (t->isBlack)
    c--;
  if (t->isNull)
    return (c == 0);
  return caminho(t->left, c) && caminho(t->right, c);
}

int maxv(Node t){
  if (t->isNull){return 0;}
  int lmax = maxv(t->left);
  int rmax = maxv(t->right);
  int value = max(lmax, rmax);
  return max(value, t->value);
}

int minv(Node t){
  if (t->isNull){return 999999999;}
  int lmin = minv(t->left);
  int rmin = minv(t->right);
  int value = min(lmin, rmin);
  return min(value, t->value);
}

bool binaria(Node t) {

  if (t->isNull)
    return true;
  //cout << maxv(t->left) << ' ' << (t->value) << ' ' << minv(t->right);

  if ((maxv(t->left) > (t->value)) && !t->left->isNull) {return false;}
  if ((minv(t->right) < (t->value)) && !t->right->isNull) {return false;}

  return (binaria(t->right) && binaria(t->left));
}

// ---------------------------------------------------

int main()
{
  Node root;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    root = readPreOrder();
    // printf("Tree with %d nodes (min=%d, max=%d)\n", size(root), minimum(root), maximum(root));
    if (!root->isBlack)
    {
      cout << "NAO" << endl;
      continue;
    }
    else if (!null(root))
    {
      cout << "NAO" << endl;
      continue;
    }
    else if (!reds(root))
    {
      cout << "NAO" << endl;
      continue;
    }
    else if (!caminho(root, smth(root)))
    {
      cout << "NAO" << endl;
      continue;
    }
    else if (!binaria(root))
    {
      cout << "NAO" << endl;
      continue;
    }
    else
      cout << "SIM" << endl;
  }

  return 0;
}
