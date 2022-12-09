/* Set.h
Copyright (c) 2014 by Michael Zahniser

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "DataNode.h"
#include "Outfit.h"
#include "Trade.h"

#include <string>

class MissionHaulerObjective {
	// Construct and Load() at the same time.
	MissionHaulerObjective(const DataNode &node, const int offset);
	void Load(const DataNode &node, const int offset);
	bool CanBeRealized() const;
	int RealizeCount() const;

	std::string id;
	int count = 0;
	int limit = 0;
	double probability = 0.;
};

class MissionCargoObjective : MissionHaulerObjective {
	static Trade::Commodity PickCommodity(const System &from, const System &to);
	std::string RealizeCargo(const System &from, const System &to) const;
};

class MissionOutfitObjective : MissionHaulerObjective {
	Outfit RealizeOutfit() const;
};

class MissionOutfitterObjective : MissionHaulerObjective {
	Outfit RealizeOutfit() const;
};
