#include "TodoItem.h"

#include <utility>


// Constructor
TodoItem::TodoItem(std::string  title) : title(std::move(title)) {}

// Getter Methods
std::string TodoItem::getTitle() const {
    return title;
}

std::string TodoItem::getDescription() const {
    return description;
}

bool TodoItem::isCompleted() const {
    return completed;
}


// Setter Methods
void TodoItem::setTitle(const std::string &new_title) {
    title = new_title;
}

void TodoItem::setDescription(const std::string &new_description) {
    description = new_description;
}

void TodoItem::toggleCompleted() {
    completed = !completed;
}
