=========================================================================================


 					 __  __ _____ _   _ _____ _____ _____ __  __ _____  
 					|  \/  |_   _| \ | |_   _/ ____|_   _|  \/  |  __ \ 
 					| \  / | | | |  \| | | || |  __  | | | \  / | |__) |
 					| |\/| | | | | . ` | | || | |_ | | | | |\/| |  ___/ 
 					| |  | |_| |_| |\  |_| || |__| |_| |_| |  | | |     
					|_|  |_|_____|_| \_|_____\_____|_____|_|  |_|_|     

								 	  Project by:
									 THOMAS GESLIN
									 VICTOR JULIEN
========================================================================================                                                     
                                                     
This software allows user to modify and save PPM pictures with a list of effects called 
LUTs (Look Up Table) entered from the command line. Here's the list of the 
available commands:


- ADDLUM value: increases the luminosity of the picture by the specified value.

- DIMLUM value: decreases the luminosity of the picture by the specified value.

- ADDCON value: increases the contrast of the picture by the specified value.

- DIMLUM value: decreases the contrast of the picture by the specified value.

- SEPIA: applies a sepia effect on the picture.

- BW: transforms a RGB picture into a black and white picture.



The original pictures must be placed in the folder /pics.
The synthax to follow is:

./bin/minigimp NameOfTheOriginalPicture.ppm COMMAND valueIfNeeded NameOfTheNewPicture.ppm



