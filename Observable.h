#pragma once

#include <list>

/// <summary>
/// IEventListener - ��������� ���������.
/// Observable - ����� �������, �������� ������� / �� ������� ���������.
/// </summary>

class IEventListener
{
public:

	virtual void updateByEvent(MyEvent event) = 0;

};

class Observable
{
private:

	std::list<IEventListener*> listeners_;

protected:

	/// <summary>
	/// �������� ����� ������ - ��������� � ����� ������� ���, ��� ��� �������.
	/// </summary>

	void notifyListener(MyEvent event) const
	{
		for (auto listener : listeners_)
		{
			listener->updateByEvent(event);
		}
	}

public:

	void addListener(IEventListener* listener)
	{
		listeners_.push_back(listener);
	}

	void remoteListener(IEventListener* listener)
	{
		listeners_.remove(listener);
	}

};