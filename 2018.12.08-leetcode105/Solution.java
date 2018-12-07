package com.shtel.bss.dataengine.increment.datasource.errorcode;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static TreeNode binaryTree(TreeNode node, List<Integer> preOrder, List<Integer> inOrder) {
        if (preOrder.isEmpty()) {
            node = null;
        } else {
            Integer val = preOrder.get(0);
            int preIndex = preOrder.indexOf(val);
            int inIndex = inOrder.indexOf(val);
            List<Integer> plOrder = preOrder.subList(preIndex + 1, inIndex + 1);
            List<Integer> prOrder = preOrder.subList(inIndex + 1, preOrder.size());

            List<Integer> ilOrder = inOrder.subList(0, inIndex);
            List<Integer> irOrder = inOrder.subList(inIndex + 1, inOrder.size());
            TreeNode useNode;
            if (node == null) {
                node = new TreeNode(val, null, null);
                useNode = node;
            } else {
                TreeNode temp = new TreeNode(val, null, null);
                useNode = temp;
                if (preIndex == inIndex) {
                    node.setRight(temp);
                } else {
                    node.setLeft(temp);
                }
            }
            binaryTree(useNode, plOrder, ilOrder);
            binaryTree(useNode, prOrder, irOrder);
        }
        return node;
    }

    public static void main(String[] args) {
        List<Integer> preOrder = new ArrayList<>();
        preOrder.add(3);
        preOrder.add(9);
        preOrder.add(20);
        preOrder.add(15);
        preOrder.add(7);
        List<Integer> inOrder = new ArrayList<>();
        inOrder.add(9);
        inOrder.add(3);
        inOrder.add(15);
        inOrder.add(20);
        inOrder.add(7);
        System.out.println(binaryTree(null, preOrder, inOrder));
    }
}

@Data
@AllArgsConstructor
@NoArgsConstructor
@ToString
class TreeNode {
    private int val;
    private TreeNode left;
    private TreeNode right;
}