# Test Data

## Test Case 1: Lighting Load
| Input | Value |
|-------|-------|
| Load Name | Workshop Lighting |
| Supply Voltage | 230 V |
| Load Power | 800 W |
| Cable Length | 25 m |
| Voltage Drop Factor | 0.02 |

**Expected Results:**
- Load Current: 3.48 A
- Voltage Drop: 1.74 V
- Recommended Cable: 1.5 mm2 lighting cable
- Advisory Message: Suitable for small lighting loads
- Voltage Drop Status: Acceptable Voltage Drop




## Test Case 2: Socket Load
| Input | Value |
|-------|-------|
| Load Name | Room Sockets |
| Supply Voltage | 230 V |
| Load Power | 2000 W |
| Cable Length | 15 m |
| Voltage Drop Factor | 0.02 |

**Expected Results:**
- Load Current: 8.70 A
- Voltage Drop: 2.61 V
- Recommended Cable: 2.5 mm2 socket/light duty cable
- Advisory Message: Suitable for small socket or small appliance loads
- Voltage Drop Status: Acceptable Voltage Drop



## Test Case 3: Water Heater
| Input | Value |
|-------|-------|
| Load Name | Water Heater |
| Supply Voltage | 230 V |
| Load Power | 3500 W |
| Cable Length | 30 m |
| Voltage Drop Factor | 0.02 |

**Expected Results:**
- Load Current: 15.22 A
- Voltage Drop: 9.13 V
- Recommended Cable: 4.0 mm2 medium load cable
- Advisory Message: Suitable for moderate appliance loads
- Voltage Drop Status: High Voltage Drop



## Test Case 4: High Load
| Input | Value |
|-------|-------|
| Load Name | Industrial Motor |
| Supply Voltage | 230 V |
| Load Power | 8000 W |
| Cable Length | 40 m |
| Voltage Drop Factor | 0.02 |

**Expected Results:**
- Load Current: 34.78 A
- Voltage Drop: 27.83 V
- Recommended Cable: Special design required
- Advisory Message: Consult a qualified electrical engineer or standard cable table
- Voltage Drop Status: High Voltage Drop

---

## Test Case 5: Invalid Input
| Input | Value |
|-------|-------|
| Supply Voltage | 0 V |
| Load Power | 800 W |
| Cable Length | 25 m |
| Voltage Drop Factor | 0.02 |

**Expected Results:**
- Error: Supply voltage must be greater than zero
- Please re-enter all details for this circuit