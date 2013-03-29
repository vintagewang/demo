#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// 增加一段中文

typedef struct Btree_node_t{
    char                    data;
    struct  Btree_node_t    *left_child;
    struct  Btree_node_t    *right_child;
}btree_node_t;

/*
 * 例如:ABC##DE#G##F###
 *      AB##C##
 */
btree_node_t *btree_create(btree_node_t *t)
{
    char        ch;

    ch = getchar();

    if (ch == '#') t = NULL;
    else {
        if (!(t = (btree_node_t *)malloc(sizeof(btree_node_t))))
            printf("malloc error %d [%d] [%s]\n", t, errno, strerror(errno));
        t->data = ch;
        t->left_child = btree_create(t->left_child);
        t->right_child = btree_create(t->right_child);
    }

    return t;
}

btree_node_t *btree_create2(btree_node_t *t, char *s)
{
    if (s) {
        fwrite(s, 1, strlen(s), stdin);
        fflush(stdin);
    }
    return btree_create(t);
}

void btree_preorder(btree_node_t *t)
{
    if (t) {
        printf("%c", t->data);
        btree_preorder(t->left_child);
        btree_preorder(t->right_child);
    }
}

void btree_inorder(btree_node_t *t)
{
    if (t) {
        btree_preorder(t->left_child);
        printf("%c", t->data);
        btree_preorder(t->right_child);
    }
}

void btree_postorder(btree_node_t *t)
{
    if (t) {
        btree_preorder(t->left_child);
        btree_preorder(t->right_child);
        printf("%c", t->data);
    }
}


int btree_sumleaf(btree_node_t *t)
{
    int sum=0,m,n;

    if (t) {
        if((!t->left_child)&&(!t->right_child))
            sum++;
        m = btree_sumleaf(t->left_child);
        sum +=m;
        n = btree_sumleaf(t->right_child);
        sum +=n;
    }
    return sum;
}

int btree_height(btree_node_t *t)
{
    int height = 0, hleft, hright;
    if (!t)
        height = 0;
    else {
        hleft = btree_height(t->left_child);
        hright = btree_height(t->right_child);
        height = 1+(hleft > hright ? hleft : hright);
    }
    return height;
}

#if 1
int main(int argc, char **argv)
{
    btree_node_t    *tree_head = NULL;

    printf("请输入二叉树:\n");
#if 1
    tree_head = btree_create(tree_head);
#else
    tree_head = btree_create2(tree_head, argv[1]);
#endif

    printf("前序遍历:\n");
    btree_preorder(tree_head);printf("\n");
    printf("中序遍历:\n");
    btree_inorder(tree_head);printf("\n");
    printf("后序遍历:\n");
    btree_postorder(tree_head);printf("\n");

    printf("二叉树的叶子数: %d\n", btree_sumleaf(tree_head));
    printf("二叉树的高度: %d\n", btree_height(tree_head));

    printf("\n");
    system("PAUSE");
    return 0;
}
#endif
