#include <iostream>
#include <SFML/Graphics.hpp>

#include "MyEvent.h"
#include "Observable.h"
#include "Button.h"

/// <summary>
/// Пример работы паттерна "Наблюдатель"
/// </summary>

class ExampleListener : public IEventListener
{
public:

    /// <summary>
    /// Весь кайф заключается в том, что наблюдатель решает, как обрабатывать событие, а не сам наблюдаемые обьект.
    /// Последний лишь меняет свой внешний вид в зависимости от состояния.
    /// 
    /// Может случиться проблема, если слушатель следит за 2 обьектами, тогда это можно решить следующим образом:
    ///     1) Сделать вложенный класс, который будет реализовывать интерфейс слушателя и при подписке на событие передавать его.
    ///     2) Сделать поле source родительского класса для всех GUI элементов в классе MyEvent, чтобы узнать, кто является источник события.
    /// </summary>

    void updateByEvent(MyEvent event) override
    {
        switch (event.type)
        {
        case MyEvent::ButtonClick:
            std::cout << "click!\n";
            break;

        case MyEvent::MouseEntered:
            std::cout << "enter!\n";
            break;

        case MyEvent::MouseLeave:
            std::cout << "leave!\n";
            break;
        }
    }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Test");
    window.setFramerateLimit(60);

    Button btn(&window);

    //Добавляем слушателя к кнопке.
    ExampleListener listener;

    btn.addListener(&listener);

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();
        window.draw(btn);
        window.display();
    }

    return 0;
}
