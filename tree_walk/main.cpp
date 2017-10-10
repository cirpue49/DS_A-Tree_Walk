//
//  main.cpp
//  tree_walk
//
//  Created by 村上候助 on 2017/10/10.
//  Copyright © 2017 村上候助. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#define NIL -1

using namespace std;

struct Node {
    int parent;
    int left;
    int right;
};

Node nodes[30];

void pre_parse(int u){
    if (u == NIL) return;
    cout << " "<< u;
    pre_parse(nodes[u].left);
    pre_parse(nodes[u].right);
}

void in_parse(int u){
    if (u == NIL) return;
    in_parse(nodes[u].left);
    cout << " "<< u;
    in_parse(nodes[u].right);
}

void post_parse(int u){
    if (u == NIL) return;
    post_parse(nodes[u].left);
    post_parse(nodes[u].right);
    cout << " "<< u;
}

int main(int argc, const char * argv[]) {
    int n, i, id, l, r, u, head;
    scanf("%d", &n);
    for(i = 0; i < n; i++) nodes[i].parent = nodes[i].left = nodes[i].right = NIL;
    for(i = 0; i < n; i++){
        scanf("%d", &id);
        scanf("%d", &l);
        scanf("%d", &r);
        nodes[i].left = l;
        nodes[i].right = r;
        if(l != NIL) nodes[l].parent = id;
        if(r != NIL) nodes[r].parent = id;
    }
    for(i = 0; i < n; i++) {
        if(nodes[i].parent == NIL) head = i;
    }
    
    cout << "Preorder" << endl;;
    pre_parse(head);
    cout <<endl;
    
    cout << "Inorder" << endl;;
    in_parse(head);
    cout <<endl;
    
    cout << "Postorder" << endl;;
    post_parse(head);
    cout <<endl;
    
    
//    std::cout << "Hello, World!\n";
    return 0;
}
