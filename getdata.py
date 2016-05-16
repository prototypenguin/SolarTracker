import serial
ser = serial.Serial("/dev/ttyACM0",9600) 


class listes(object):
    
    def make(self, lmax, char, liste):
        """Takes the folliwing parametres and appends taken values to the list:
            lmax: max list length
            char: must be equal to the IF-'CHAR' on Arduino, CHAR been a letter from A to Z
            liste: predefined global list on main.py
        """

        if len(liste) != lmax:
             ser.write(char)
             val = int(ser.readline())
             liste.append(val)
                
        else:
        
            del liste[:]
            ser.write(char)
            val = int(ser.readline())
            liste.append(val)
        
        return liste

class talk(object):
    
    def getintval(self, char):

        ser.write(char)
        val = int(ser.readline())
        
        return val
    
    def getstrval(self, char):

        ser.write(char)
        val = ser.readline()
                
        return val
        
    def tell(self, char):

        ser.write(char)
        
        return val
