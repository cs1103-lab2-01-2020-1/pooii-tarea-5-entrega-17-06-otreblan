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

#include <functional>

#include <parking.hpp>

void aru::Parking::register_user(User& user)
{
	signal_map.emplace(user.name,
		signal.connect(
			std::bind(
				&User::notify,
				user,
				notify_type::parking,
				std::placeholders::_1
			)
		)
	);
}

void aru::Parking::unregister_user(User& user)
{
	auto it = signal_map.find(user.name);

	if(it != signal_map.end())
	{
		it->second.disconnect();
		signal_map.erase(it);
	}
}


void aru::Parking::run()
{
}
