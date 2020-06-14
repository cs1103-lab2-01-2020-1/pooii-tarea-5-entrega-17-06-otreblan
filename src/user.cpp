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

#include <user.hpp>
#include <notifier.hpp>
#include <parking.hpp>

aru::User::User(std::string_view name):
	name(name)
{};

void aru::User::notify(Notifier& notifier, notify_type type)
{
	switch (type) {
		case notify_type::parking:
		{
			auto& parking = static_cast<Parking&>(notifier);

			int count = 0;

			for(const auto& i:parking.parks)
			{
				if(!i)
					count++;
			}
			std::cout << count << '\n';
			break;
		}
		case notify_type::tables:
			break;
	}
}
