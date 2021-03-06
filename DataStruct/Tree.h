#pragma once

#ifndef ZYCPP_TREE_NODE_H
#define ZYCPP_TREE_NODE_H

namespace zycpp {
template <typename K>
struct LessThan {
  constexpr bool operator()(const K& lhs, const K& rhs) const { return lhs < rhs; }
};

template <typename K, typename V>
class TreeNode {
 public:
  using ThisType = TreeNode<K, V>;
  K k_;
  V v_;
  ThisType* left_;
  ThisType* right_;

  TreeNode(K k, V v) noexcept : k_(k), v_(v), left_(nullptr), right_(nullptr) {}

  virtual ~TreeNode() {
    delete left_;
    delete right_;
  }
};

template <typename K, typename V>
class AVLNode : public TreeNode<K, V> {
 public:
  int hight_;

  AVLNode(K k, V v) noexcept : TreeNode<K, V>(k, v), hight_(1) {}
};
}  // namespace zycpp

#endif