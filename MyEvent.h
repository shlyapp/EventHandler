#pragma once

/// <summary>
/// ������ ����� ������ � ���� ��� �������. ����� ������������ � ���� �� ���, � ����������� ���������� � sf::Event
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