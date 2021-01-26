#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {

	public:
		PowerFist(void);
		PowerFist(PowerFist const & src);

		virtual void attack(void) const;

		PowerFist & operator=(PowerFist const & src);

		virtual ~PowerFist(void);

};

#endif
