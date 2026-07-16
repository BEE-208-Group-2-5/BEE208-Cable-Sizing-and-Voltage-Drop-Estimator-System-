BEGIN
    DISPLAY "CABLE SIZING AND VOLTAGE DROP ESTIMATOR SYSTEM"
    
    PROMPT "Enter number of circuits to analyse: "
    INPUT numCircuits
    
    WHILE numCircuits <= 0 DO
        DISPLAY "Invalid number. Please enter a positive number."
        PROMPT "Enter number of circuits to analyse: "
        INPUT numCircuits
    END WHILE
    
    OPEN FILE "cable_sizing_report.txt" FOR WRITING
    
    FOR i = 1 TO numCircuits DO
        PROMPT "Enter load name: "
        INPUT loadName
        PROMPT "Enter supply voltage in volts: "
        INPUT supplyVoltage
        PROMPT "Enter load power in watts: "
        INPUT loadPower
        PROMPT "Enter cable length in metres: "
        INPUT cableLength
        PROMPT "Enter voltage drop factor: "
        INPUT voltageDropFactor
        
        IF supplyVoltage <= 0 OR loadPower <= 0 OR cableLength <= 0 OR voltageDropFactor <= 0 THEN
            DISPLAY "Invalid input. All values must be positive."
            i = i - 1
            CONTINUE
        END IF
        
        loadCurrent = loadPower / supplyVoltage
        voltageDrop = loadCurrent * cableLength * voltageDropFactor
        
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
        
        IF voltageDrop <= (supplyVoltage * 0.04) THEN
            vdStatus = "Acceptable Voltage Drop"
        ELSE
            vdStatus = "High Voltage Drop"
        END IF
        
        DISPLAY "Load Current: " + loadCurrent + " A"
        DISPLAY "Approximate Voltage Drop: " + voltageDrop + " V"
        DISPLAY "Recommended Cable: " + recommendedCable
        DISPLAY "Voltage Drop Status: " + vdStatus
        
        WRITE TO FILE: loadName, loadCurrent, voltageDrop, recommendedCable, vdStatus
    END FOR
    
    CLOSE FILE
    DISPLAY "Report saved to cable_sizing_report.txt"
    DISPLAY "Thank you for using the Cable Sizing Estimator!"
END