void padding(int n){
  for(int i = 0; i < n; i++ )
    printf("\t");
}
void print_node(avl_node *node, int level) {
  int h_right = height(node->right);
  int h_left = height(node->left);
  int h = h_right > h_left ? h_right : h_left;

  char str[32];
  sprintf(str, "(\x1b[1m%d\x1b[0m|h:%d)", node->data, h);
  printf("%s", str);

  int dash = 80 - (level * 8); // 80 is the total available space, level * 8 is the tab size

  // For each caracter on string remove 1 from dash
  // Starts in 14 because str has 14 non-print characters (like \x1b[1m for coloring)
  for(int i=14; str[i] != '\0'; i++) dash--;

  for(int i=0; i < dash; i++) printf("-");
  puts("");
}
void print_tree (Node *root, int level){

  if (!root) {
    padding (level+1);
    puts("~");
  }
  else {
    print_tree (root->right, level + 1);
    padding (level + 1);
    print_node(root, level + 1);
    print_tree(root->left, level + 1);
  }
}
