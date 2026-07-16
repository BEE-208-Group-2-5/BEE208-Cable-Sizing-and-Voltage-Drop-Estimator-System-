START
1. Display "CABLE SIZING AND VOLTAGE DROP ESTIMATOR SYSTEM"
2. Display project title and welcome message
3. Ask user: "Enter number of circuits to analyse: "
4. Read numCircuits
5. IF numCircuits <= 0 THEN
      Display "Invalid number. Please enter a positive number."
      Go back to step 3
   END IF
6. FOR i = 1 TO numCircuits DO
      a. Ask: "Enter load name: "
      b. Read loadName
      c. Ask: "Enter supply voltage in volts: "
      d. Read supplyVoltage
      e. Ask: "Enter load power in watts: "
      f. Read loadPower
      g. Ask: "Enter cable length in metres: "
      h. Read cableLength
      i. Ask: "Enter voltage drop factor: "
      j. Read voltageDropFactor
      
      k. Validate inputs:
         IF supplyVoltage <= 0 OR loadPower <= 0 OR cableLength <= 0 OR voltageDropFactor <= 0 THEN
            Display "Invalid input. Values must be positive."
            Decrement i and restart this circuit
         END IF
      
      l. Calculate loadCurrent = loadPower / supplyVoltage
      
      m. Calculate voltageDrop = loadCurrent * cableLength * voltageDropFactor
      
      n. Recommend cable size:
         IF loadCurrent <= 5 THEN
            recommendedCable = "1.5 mm2 lighting cable"
            advisoryMessage = "Suitable for small lighting loads"
         ELSE IF loadCurrent <= 13 THEN
            recommendedCable = "2.5 mm2 socket/light duty cable"
            advisoryMessage = "Suitable for light socket or small appliance loads"
         ELSE IF loadCurrent <= 20 THEN
            recommendedCable = "4.0 mm2 medium load cable"
            advisoryMessage = "Suitable for moderate appliance loads"
         ELSE IF loadCurrent <= 32 THEN
            recommendedCable = "6.0 mm2 high load cable"
            advisoryMessage = "Suitable for higher current circuits"
         ELSE
            recommendedCable = "Special design required"
            advisoryMessage = "Consult a qualified electrical engineer"
         END IF
      
      o. Determine voltage drop status:
         IF voltageDrop <= (supplyVoltage * 0.04) THEN
            vdStatus = "Acceptable Voltage Drop"
         ELSE
            vdStatus = "High Voltage Drop"
         END IF
      
      p. Display report for this circuit
      
      q. Append to report file: cable_sizing_report.txt
   END FOR
7. Display "Report saved to cable_sizing_report.txt"
8. Display closing message
9. STOP