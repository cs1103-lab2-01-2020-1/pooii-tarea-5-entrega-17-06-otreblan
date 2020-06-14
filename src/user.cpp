// Observer
// Copyright © 2020 otreblan
//
// observer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// observer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with observer.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>

#include <libnotify/notify.h>

#include <user.hpp>
#include <notifier.hpp>
#include <parking.hpp>

aru::User::User(std::string_view name):
	name(name)
{};

void aru::User::notify(notify_type type, int cuantity)
{
	using namespace std::literals;

	std::string cuantity_str = std::to_string(cuantity);
	std::string title;

	switch (type) {
		case notify_type::parking:
			title = "Parking lot";
			break;
		case notify_type::tables:
			break;
	}

	notify_init("observer");

	NotifyNotification* notification = notify_notification_new(
		title.c_str(),
		(cuantity_str + " free space"s + (cuantity == 1? ""s: "s"s)).c_str(),
		nullptr
	);

	notify_notification_show(notification, nullptr);

	g_object_unref(G_OBJECT(notification));

	notify_uninit();
}
