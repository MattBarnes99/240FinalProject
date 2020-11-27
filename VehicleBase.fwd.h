#pragma once
class VehicleBase;

//Needed to get around the circular dependencies created between Section and VehicleBase
//Both need instance variables of the other so using this and the Section forward header file
//solves that issue.