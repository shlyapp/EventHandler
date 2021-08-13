#pragma once

/// <summary>
///  ласс Button наследует sf::Drawable дл€ отрисовки и реализует интерфейс Observable дл€ возможности подписки на свои событий.
/// Ётот класс €вл€етс€ лишь графическим отображением и не реализует обработку своих событий, а лишь измен€ет внешний вид от состо€ни€.
/// </summary>

class Button : public sf::Drawable, public Observable
{
private:

	mutable MyEvent event;
	sf::RenderWindow* window_;

	mutable sf::RectangleShape rectangle_;

	/// <summary>
	/// ¬ следующих методах происходит изменение своего вида в зависимости от событи€, а так же оповещение(!) подписчиков о изменении.
	/// </summary>

	void click() const
	{
		if (event.type != MyEvent::ButtonClick)
		{
			event.type = MyEvent::ButtonClick;

			notifyListener(event);
		}
	}

	void enter() const
	{

		if (event.type != MyEvent::MouseEntered)
		{
			event.type = MyEvent::MouseEntered;

			notifyListener(event);
		}

		rectangle_.setFillColor(sf::Color::Green);
	}

	void leave() const
	{
		if (event.type != MyEvent::MouseLeave)
		{
			event.type = MyEvent::MouseLeave;

			notifyListener(event);
		}

		rectangle_.setFillColor(sf::Color::Red);
	}

public:

	Button(sf::RenderWindow* window) : window_(window)
	{
		rectangle_.setSize(sf::Vector2f(100, 100));
		rectangle_.setPosition(sf::Vector2f(50, 50));
		rectangle_.setFillColor(sf::Color::Red);
	}

	void draw(sf::RenderTarget& target, sf::RenderStates animation_state) const override
	{
		sf::Vector2f mousePosition = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));

		if (((rectangle_.getPosition().x <= mousePosition.x) && (rectangle_.getPosition().x + rectangle_.getSize().x) >= mousePosition.x) && (rectangle_.getPosition().y <= mousePosition.y && ((rectangle_.getPosition().y + rectangle_.getSize().y) >= mousePosition.y)))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				click();
			}
			else
			{
				enter();
			}
		}
		else
		{
			leave();
		}

		target.draw(rectangle_);
	}

};