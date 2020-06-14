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

#include <string_view>
#include <iostream>
#include <sstream>

#include <env.hpp>

void aru::Env::help()
{
	std::cout << "TODO: help\n";
}

std::pair<bool, std::string>
	aru::Env::action(std::string_view str, std::istream& is)
{
	auto it = action_map.find(str);

	if(it == action_map.end())
		return {false, "Action not found\n"};

	return it->second(*this, is);
}

void aru::Env::login(const std::string& new_user)
{
	auto it = users.find(new_user);

	// User not found
	if(it == users.end())
	{
		std::shared_ptr<User> user(new User(new_user));
		users[new_user] = user;

		current_user = *user;
	}
	else // User found
	{
		current_user = *it->second;
	}
}

void aru::Env::logout()
{
	current_user.reset();
}

const std::unordered_map<std::string_view,
	std::function<std::pair<bool, std::string>(aru::Env&, std::istream&)>>
		aru::Env::action_map =
{
	{
		"help",
		[](Env& env, std::istream& is) -> std::pair<bool, std::string>
		{
			env.help();

			std::string s_buf;
			std::getline(is, s_buf);

			return {true, ""};
		}
	},
	{
		"login",
		[](Env& env, std::istream& is) -> std::pair<bool, std::string>
		{
			std::string s_buf;

			if(std::getline(is, s_buf, ' '))
				env.login(s_buf);
			else
				return {false, "login \e[4muser\e[0m\n"};

			std::getline(is, s_buf);

			return {true, ""};
		}
	},
	{
		"logout",
		[](Env& env, std::istream& is) -> std::pair<bool, std::string>
		{
			env.logout();

			std::string s_buf;
			std::getline(is, s_buf);

			return {true, ""};
		}
	},
	{
		"park-register",
		[](Env& env, std::istream& is) -> std::pair<bool, std::string>
		{
			if(!env.current_user.has_value())
				return {false, "login \e[4muser\e[0m\n"};

			env.parking.register_user(env.current_user.value());

			std::string s_buf;
			std::getline(is, s_buf);

			return {true, ""};
		}
	}
};
