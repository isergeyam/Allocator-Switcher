//
// Created by sg on 11.04.18.
//
#include "GlobalManager.hpp"
IMemoryManager *CGlobalManager::TopAllocator() { return current_node->current_manager; }
void CGlobalManager::PushAllocator(IMemoryManager *new_manager) {
  current_node = new(std::malloc(sizeof(SManagerNode))) SManagerNode(new_manager, current_node);
}
CGlobalManager::SManagerNode *CGlobalManager::current_node =
    new (std::malloc(sizeof(SManagerNode))) SManagerNode(new (std::malloc(sizeof(CDefaultAllocator))) CDefaultAllocator, nullptr);
void CGlobalManager::PopAllocator() {
  current_node = current_node->prev_node;
}
CGlobalManager::SManagerNode::SManagerNode(IMemoryManager *current_manager, CGlobalManager::SManagerNode *prev_node)
    : current_manager(current_manager), prev_node(prev_node) {}

