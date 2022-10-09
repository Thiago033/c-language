void rotationLL(node** root) {
//     struct node* rootPtr = *root;
//     struct node* node;

//     node = rootPtr->pLeft;

//     rootPtr->pLeft = node->pRight;

//     node->pRight = rootPtr; // ?????????

//     rootPtr->height = greater(nodeHeight(rootPtr->pLeft), nodeHeight(rootPtr->pRight)) + 1;

//     node->height = greater(nodeHeight(node->pLeft), rootPtr->height) + 1;

//     rootPtr = node;
// }