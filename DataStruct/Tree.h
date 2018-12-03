#pragma once

#ifndef ZYCPP_TREE_H
#define ZYCPP_TREE_H

namespace zycpp {
    template<typename K, typename V>
    class TreeNode {
    private:
        K k_;
        V v_;
    public:
        K key();
        V val();
    };
}

#endif