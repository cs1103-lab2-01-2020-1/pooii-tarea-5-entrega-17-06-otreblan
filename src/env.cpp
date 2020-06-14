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

#include <env.hpp>
#include <string_view>

void aru::Env::help()
{
}

void aru::Env::login(std::string_view new_user)
{
	if(users.find((std::string)new_user) == users.end())
		return;

	std::shared_ptr<User> user(new User(new_user));
	users[(std::string)new_user] = user;

	current_user = *user;
}

void aru::Env::logout()
{
	current_user.reset();
}
