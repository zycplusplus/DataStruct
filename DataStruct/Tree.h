#pragma once

#ifndef ZYCPP_BSTREE_NODE_H
#define ZYCPP_BSTREE_NODE_H

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

  TreeNode(const ThisType& tn) noexcept : k_(tn.k_), v_(tn.v_), left_(tn.left_), right_(tn.right_) {}

  virtual ~TreeNode() {
    delete left_;
    delete right_;
  }
};
}  // namespace zycpp

#endif