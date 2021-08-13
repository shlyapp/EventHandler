#pragma once

/// <summary>
/// Данный класс хранит в себе тип события. Можно использовать в коде не его, а реализовать интеграцию с sf::Event
/// </summary>

class MyEvent
{
public:

    enum EventType
    {
        ButtonClick,
        MouseEntered,
        MouseLeave
    };

   EventType type;

};