#pragma once

#include <string>

class TodoItem {

    std::string title;
    std::string description;
    bool completed {};

public:
    explicit TodoItem(std::string title);

    // Getter Methods
    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] bool isCompleted() const;

    // Setter Methods
    void setTitle(const std::string& new_title);
    void setDescription(const std::string& new_description);
    void toggleCompleted();
};
