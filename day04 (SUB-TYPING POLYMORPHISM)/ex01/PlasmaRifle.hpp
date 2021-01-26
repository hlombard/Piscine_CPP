#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const & src);

		virtual void attack(void) const;

		PlasmaRifle & operator=(PlasmaRifle const & src);

		virtual ~PlasmaRifle(void);

};

#endif
