# C++ FOR CREATIVE PRACTICE FINAL PROJECT

<img src="https://github.com/jawknee-h/the-pit/assets/121831154/6417156b-475a-4107-8bf2-706c7392d26a" width="100%">

#### Languages, libraries, and frameworks
* C++
* openFrameworks
#### Tools used
* Blender
    - 3D Modelling
    - Texturing
    - UV Unwrapping
 * Ableton Live
    - Synthesising the ambient background audio
 
 #### Video demonstration

https://github.com/jawknee-h/the-pit/assets/121831154/dc303c41-138e-4668-a586-eb3fe23a2709

#### Description of the purpose of the program
I wanted to create something visceral and emotional. I aimed to tap into the human
subconscious and make anyone who saw it feel ways that they didn’t understand--feelings of
dread, hopelessness, and unease--but also peace; in that way I suppose it’s more of an art piece or a
mini film.

<img src="https://github.com/jawknee-h/the-pit/assets/121831154/98d3cae9-7deb-4477-a6cf-372be370c84e" width="24%">
<img src="https://github.com/jawknee-h/the-pit/assets/121831154/7d8901a0-e16e-4cfd-ba79-78c02bcc277e" width="24%">
<img src="https://github.com/jawknee-h/the-pit/assets/121831154/ce2e3880-de7f-46ba-9228-025931e120bd" width="24%">
<img src="https://github.com/jawknee-h/the-pit/assets/121831154/3f9a6a54-40e7-42d1-abd6-d48dac98b5bb" width="24%">
<img src="https://github.com/jawknee-h/the-pit/assets/121831154/b6eb430e-9b8e-46cd-b62e-8c26b646b665" width="24%">
<img src="https://github.com/jawknee-h/the-pit/assets/121831154/42d2ac60-9970-4ea2-85d2-d8bb01955ae4" width="24%">
<img src="https://github.com/jawknee-h/the-pit/assets/121831154/fc0b842b-d41f-4827-8a18-cef626da6be6" width="24%">
<img src="https://github.com/jawknee-h/the-pit/assets/121831154/0fd6622b-cd82-46c6-92eb-2ce9afada63e" width="24%">

#### Features
* Centipede class:
    - Represents a chain-like creature made up of a head, a tail, and a variable number of links between. Can be used to produce a variety of creatures by tweaking the models used and the length, scale and speed. The beetles and the large centipede are both made with the centipede class.
    - Can follow a path
        .In this example the large centipede is following a hand-designed path to give me complete control over its choreography, while the beetles follow their own stochastically generated paths.
* Camera shake:
* Simple animation-player system:
    - Used for timing the camera shake and the movement of the different centipedes and beetles in this example.
 
    

#### Description and documentation of the behaviour of the program
It’s unclear what or where it is, but it aims to be uncomfortable to look at.
There's a pit lined with teeth and eyes in the center of the frame.
Initially a swarm of small beetles flee from the pit; the path that each beetle takes is generated stochastically when the application begins.
The camera will begin to shake.. Subtly at first, then more violently until a centipede 100 times
the size, which has also been procedurally generated and animated, emerges from the pit to chase
them. My centipede follows a hard-coded path, unlike the beetles,
which allows me to have full control over where it goes and when. I did this so that I could hand
choreograph its movement to ensure it moves in a cinematic way - just barely missing the camera
and such. After flying around, the centipede plunges back into the pit, causing tremors.
All the while, the camera is slowly dollying towards the pit while the camera’s field of view
increases at an equal but opposite rate, similar to a dolly zoom (aka vertigo shot/jaws effect).
Typically in film this technique is used to convey a sudden sinking feeling, with the zoom being
performed rapidly, but what I wanted to convey was slightly different. I wanted to evoke a
feeling of dread and unease, like you’re slowly sinking or being pulled into the pit. Being pulled
so slowly that you can’t tell if you’re even actually moving at all. Some things appear to be
getting closer, but other things appear to get farther away; you start to question if you can trust
what you see; you start to understand that wherever you are, it doesn’t follow the rules that we’re
used to - it’s otherwordly. As the camera gets pulled closer to the pit and field of view continues
to grow, the world starts to warp around you, like light in a black hole. I wanted to convey this
feeling of inexplicable attraction, as if the pit has such a powerful force of attraction that not
even light can escape. Accompanying all of this is a dreamy bell sound which loops. I figured a
scene like this would naturally be as loud as it is chaotic, but I felt that using a calming, almost
hypnotic sound instead would convey that you’re so drawn to this pit that despite all of the crazy
things going on around you, you can’t help but tune everything out and stare deep into it, almost
like you’re being hypnotised or mind controlled by it.
I also used lighting to create unease. The lighting in this scene doesn’t makes sense; it doesn’t act
how we would expect it to: there is no clear lightsource and yet there are strong highlights; there
are no shadows being projected; objects which should be in shadow, like the teeth, are bright,
while other things which should be in the light, like the centipede, are very dark. It may not be
wrong enough for us to consciously notice it, but I think you can feel that something is off when
you look at it. I did this by making certain objects only influenced by their own lightsources, and
by baking highlights and shadows into textures where possible.
