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

#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <memory>
#include <functional>

#include <user.hpp>
#include <parking.hpp>

namespace aru
{
class Env
{
private:
	const static std::unordered_map<std::string_view,
		std::function<std::pair<bool, std::string>(Env&, std::istream&)>>
		action_map;

	std::unordered_map<std::string, std::shared_ptr<User>> users;

	std::optional<std::reference_wrapper<User>> current_user;

	void login(const std::string& new_user);
	void logout();

	Parking parking;
public:
	Env() = default;
	virtual ~Env() = default;

	/// Print help
	void help();

	/// Actions
	std::pair<bool, std::string> action(std::string_view str, std::istream& is);
};
};
