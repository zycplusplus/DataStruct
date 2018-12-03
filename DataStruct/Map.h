#pragma once
#include "BSTree.h"

#ifndef ZYCPP_MAP_H
#define ZYCPP_MAP_H

namespace zycpp {
    template<typename K, typename V>
    class Map {
    public:
        BSTreeNode<K, V>* root_;

        size_t size_;

        Map() noexcept:root_(nullptr),size_(0) { }

        virtual ~Map() {
            delete root_;
        }

        void Insert(const K&k, const V&v) {
            if (root_ == nullptr) {
                root_ = new BSTreeNode<K, V>(k, v);
                size_++;
            }
            else if (root_->Insert(k, v)) {
                size_++;
            }
        }

        BSTreeNode<K,V>* Find(const K& k)const {
            if (root_ == nullptr) {
                return nullptr;
            }
            return root_->Find(k);
        }
    };
}

#endif