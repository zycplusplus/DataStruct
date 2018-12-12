#pragma once
#ifndef ZYCPP_MAP_H
#define ZYCPP_MAP_H

#include "Tree.h"

namespace zycpp {
template <typename K, typename V, typename LT = LessThan<K>>
class Map {
 public:
  size_t size_;
  TreeNode<K, V>* root_;
  LT lt_;

  Map() noexcept : root_(nullptr), size_(0), lt_(LT()) {}

  virtual ~Map() { delete root_; }

  size_t size() { return size_; };

  virtual void insert(const TreeNode<K, V>& node) = 0;

  virtual void erase(const K& k) = 0;

  virtual TreeNode<K, V>* find(const K& k) const = 0;
};

template <typename K, typename V, typename LT = LessThan<K>>
class BSTMap : virtual public Map<K, V, LT> {
  using Map<K, V, LT>::root_;
  using Map<K, V, LT>::size_;
  using Map<K, V, LT>::lt_;

 public:
  virtual void insert(const TreeNode<K, V>& n) override {
    if (root_ == nullptr) {
      root_ = new TreeNode<K, V>(n);
    }
    else {
      TreeNode<K, V>* cur = root_;
      while (1) {
        K& k1       = cur->k_;
        const K& k2 = n.k_;
        if (lt_(k2, k1)) {
          if (cur->left_ == nullptr) {
            cur->left_ = new TreeNode<K, V>(n);
            break;
          }
          cur = cur->left_;
        }
        else if (lt_(k1, k2)) {
          if (cur->right_ == nullptr) {
            cur->right_ = new TreeNode<K, V>(n);
            break;
          }
          cur = cur->right_;
        }
        else {
          return;
        }
      }
    }
    size_++;
  }

  virtual void erase(const K& k) override {
    if (root_ == nullptr) {
      return;
    }

    TreeNode<K, V>* tar = root_;
    TreeNode<K, V>* par = nullptr;
    bool lc             = true;
    while (1) {
      if (lt_(k, tar->k_)) {
        if (tar->left_ == nullptr) {
          return;
        }
        par = tar;
        tar = par->left_;
        lc  = true;
        continue;
      }
      if (lt_(tar->k_, k)) {
        if (tar->right_ == nullptr) {
          return;
        }
        par = tar;
        tar = par->right_;
        lc  = false;
        continue;
      }
      break;
    }
    if (tar->left_ == nullptr && tar->right_ == nullptr) {
      if (par == nullptr) {
        root_ = nullptr;
      }
      else if (lc) {
        par->left_ = nullptr;
      }
      else {
        par->right_ = nullptr;
      }
      delete tar;
      size_--;
      return;
    }

    TreeNode<K, V>* rep = nullptr;
    if (tar->left_ == nullptr || tar->right_ == nullptr) {
      if (tar->left_ == nullptr) {
        rep = tar->right_;
      }
      else {
        rep = tar->left_;
      }
      if (par == nullptr) {
        root_ = rep;
      }
      else if (lc) {
        par->left_ = rep;
      }
      else {
        par->right_ = rep;
      }
      tar->left_  = nullptr;
      tar->right_ = nullptr;
      delete tar;
      size_--;
      return;
    }

    TreeNode<K, V>* rep_par = nullptr;
    rep                     = tar->left_;
    while (rep->right_ != nullptr) {
      rep_par = rep;
      rep     = rep_par->right_;
    }
    if (rep_par != nullptr) {
      rep_par->right_ = rep->left_;
      rep->right_     = tar->right_;
      rep->left_      = tar->left_;
    }
    else {
      rep->right_ = tar->right_;
    }
    if (par == nullptr) {
      root_ = rep;
    }
    else if (lc) {
      par->left_ = rep;
    }
    else {
      par->right_ = rep;
    }
    tar->left_  = nullptr;
    tar->right_ = nullptr;
    delete tar;
    size_--;
    return;
  }

  virtual TreeNode<K, V>* find(const K& k) const override {
    if (root_ == nullptr) {
      return nullptr;
    }
    TreeNode<K, V>* cur_node = root_;
    while (1) {
      if (lt_(k, cur_node->k_)) {
        if (cur_node->left_ == nullptr) {
          return nullptr;
        }
        cur_node = cur_node->left_;
        continue;
      }
      if (lt_(cur_node->k_, k)) {
        if (cur_node->right_ == nullptr) {
          return nullptr;
        }
        cur_node = cur_node->right_;
        continue;
      }
      return cur_node;
    }
  }

  virtual V& operator[](const K& k) { return find(k)->v_; }

  virtual const V& operator[](const K& k) const { return find(k)->v_; }
};

template <typename K, typename V, typename LT = LessThan<K>>
class AVLMap : virtual public BSTMap<K, V, LT> {
  using Map<K, V, LT>::root_;
  using Map<K, V, LT>::size_;
  using Map<K, V, LT>::lt_;

 public:
  void insert(const AVLNode<K, V>& n) {
    if (root_ == nullptr) {
      root_ = new AVLNode<K, V>(n);
    }
    else {
      AVLNode<K, V>* cur = root_;
      bool from_left     = true;
      while (1) {
        const K& input_k = n.k_;
        const K& cur_k   = cur->k_;
        if (lt_(input_k, cur_k)) {
          /// insert to left
          if (cur->left_ == nullptr) {
              cur->left_=new AVLNode<K, V>(n);
            if (cur-)
            break;
          }
        }
        else if (lt_(cur_k, input_k)) {
          /// insert to right
        }
        return;
      }
    }
    size++;
  }

  void erase(const K& k) override {}

 public:
};
}  // namespace zycpp

#endif