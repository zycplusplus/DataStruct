#pragma once

#ifndef ZYCPP_BSTREE_NODE_H
#define ZYCPP_BSTREE_NODE_H

namespace zycpp {
    template<typename K, typename V>
    class BSTreeNode {
    public:
        K k_;
        V v_;
        BSTreeNode<K, V>* left_;
        BSTreeNode<K, V>* right_;

        BSTreeNode() noexcept :k_(K()), v_(V()), left_(nullptr), right_(nullptr) {}

        explicit BSTreeNode(K k, V v)noexcept :k_(k), v_(v), left_(nullptr), right_(nullptr) {}

        BSTreeNode(const BSTreeNode<K, V>& tn) noexcept :k_(tn.k_), v_(tn.v_), left_(tn.left_), right_(tn.right_) {}

        virtual ~BSTreeNode() {
            delete left_;
            delete right_;
        }

        bool Insert(const K&k, const V&v) {
            if (k == k_) {
                return false;
            }
            if (k < k_) {
                if (left_ == nullptr) {
                    left_ = new BSTreeNode<K, V>(k, v);
                    return true;
                }
                return left_->Insert(k, v);
            }
            if (right_ == nullptr) {
                right_ = new BSTreeNode<K, V>(k, v);
                return true;
            }
            return right_->Insert(k, v);
        }

        BSTreeNode<K, V>* Find(const K&k) {
            if (k == k_) {
                return this;
            }
           
            if (k < k_) {
                if (left_ == nullptr) {
                    return nullptr;
                }
                return left_->Find(k);
            }
            if (right_ == nullptr) {
                return nullptr;
            }
            return right_->Find(k);
        }
    };
}

#endif