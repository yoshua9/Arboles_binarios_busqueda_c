/************************************************************
Autor: Yoshua Lino Troncoso
Fecha: 17/05/2020
************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // el nodo almacena un numero entero
    struct node *right_child; // hijo derecho
    struct node *left_child; // hijo izquierdo
};

//función para crear un nodo nuevo
struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

//función para insertar la información en el subarbol derecho o izquierdo dependiendo si es mayor o menor
struct node* insert(struct node *root, int x)
{
    //buscando el lugar para insertar
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // si x es mayor se inserta a la derecha
        root->right_child = insert(root->right_child, x);
    else // si el numero x es más pequeño se situa a la izquierda
        root->left_child = insert(root->left_child,x);
    return root;
}

//función para buscar un nodo en el arbol binario
struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) //si hemos encontrado el nodo que introducimos
        return root;
    else if(x>root->data) // si x es mayor buscaremos en el subarbol derecho
        return search(root->right_child, x);
    else //si x es mas pequeño buscaremos en el subarbol izquierdo
        return search(root->left_child,x);
}


int main()
{
    //creamos un nuevo nodo e insertamos los siguientes nodos a la derecha o izquierda dependiendo de su número
    struct node *root;
    root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);

    //realizamos el proceso de busqueda de un nodo en el arbol binario
    struct node *dato;
    dato=search(root,25);
    //validamos si se encentra ese nodo o no dentro de nuestro arbol binario
    if(dato == NULL){
        printf(" No existe ningun nodo con ese numero");
        printf("\n");
    }else{
        printf(" %d ", dato->data);
        printf("\n");
    }
    return 0;

}