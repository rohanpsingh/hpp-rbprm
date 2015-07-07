//
// Copyright (c) 2014 CNRS
// Authors: Steve Tonneau (steve.tonneau@laas.fr)
//
// This file is part of hpp-rbprm.
// hpp-rbprm is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-rbprm is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-core  If not, see
// <http://www.gnu.org/licenses/>.

#ifndef HPP_RBPRM_FULLBODY_HH
# define HPP_RBPRM_FULLBODY_HH

# include <hpp/rbprm/config.hh>
# include <hpp/model/device.hh>
# include <hpp/rbprm/rbprm-limb.hh>

namespace hpp {
  namespace rbprm {
    HPP_PREDEF_CLASS(RbPrmFullBody);

    /// Dual representation of a robot for Reachability Based planning:
    /// Collision free part of the robot vs Range Of Motion of the limbs.
    ///
    class RbPrmFullBody;
    typedef boost::shared_ptr <RbPrmFullBody> RbPrmFullBodyPtr_t;

    class HPP_RBPRM_DLLAPI RbPrmFullBody
    {
    public:
        static RbPrmFullBodyPtr_t create (const model::DevicePtr_t& device);

    public:
        virtual ~RbPrmFullBody();

    public:
        /// Creates a Limb for the robot,
        /// identified by its name. Stores a sample
        /// container, used for requests
        void AddLimb(const std::string& name,
                     const std::size_t nbSamples, const double resolution);

    public:
        const rbprm::T_Limb& GetLimbs() {return limbs_;}
        const model::DevicePtr_t device_;

    private:
        rbprm::T_Limb limbs_;


    protected:
      RbPrmFullBody (const model::DevicePtr_t &device);

      ///
      /// \brief Initialization.
      ///
      void init (const RbPrmFullBodyWkPtr_t& weakPtr);

    private:
      RbPrmFullBodyWkPtr_t weakPtr_;
    }; // class RbPrmDevice
  } // namespace rbprm
} // namespace hpp

#endif // HPP_RBPRM_DEVICE_HH