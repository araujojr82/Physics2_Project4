Physics 2 Project 4

Author: Euclides Araujo


The Constraints used in this project are:
BALL_AND_SOCKET,
HINGE,
6DOF,
CONE_TWIST.

They are created in TheMain.cpp harcoded to the objects in pairs, so objects 0 and 1 are for th first constraint, 2 and 3 for the second and so on.
(Line 762 and forward, just in case you're looking for it)

The objects used are Sphere, Plane, Cube and Capsule.

There's a collision response being used to change the textures in the objects while they're colliding.


Instructions:
Please compile all projects in 32 or 64 bits before execute.

User input keys:
W,A,S,D,Q,E: Controls the camera position; NOT THE BALL
Mouse wheel: Controls the camera zoom
Mouse: Controls the Pitch and Yaw of the camera

UP, DOWN, LEFT and RIGHT arrows: Control the selected ball 
TAB: Change the selected ball
ENTER: Enter the debug mode
BACKSPACE: Alternate the soft body rendering between spheres/mesh (BONUS)
ESC: Quit the application

Configuration of the scene is done via the objects.txt file.
Each line can create 1 object in the scene, the line structure is:
meshname posX posY posZ scale mass

Meshname is String pointing to the corresponding mesh in the meshlist.txt
The other values are float

meshname	  X    Y    Z  SCALE MASS
example:
ball		 0.0  0.0  7.0  1.5  7.5
ball		-3.0 -3.0  7.0  1.2  6.0
ball		 3.0  3.0  7.0  1.0  5.0
floor_plane	 0.0  0.0  0.0  4.0  0.0
north_plane	 0.0  4.0  0.0  4.0  0.0
south_plane	 0.0 -4.0  0.0  4.0  0.0
left_plane	-4.0  0.0  0.0  4.0  0.0
right_plane	 4.0  0.0  0.0  4.0  0.0