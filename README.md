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

#### Technical Features
* Centipede class:
    - Represents a chain-like creature made up of a head, a tail, and a variable number of links between. Can be used to produce a variety of creatures by tweaking the models used, the number of links, and the scale of each link. The beetles and the large centipede are both made with the centipede class.
    - Can follow a path. In this example the large centipede is following a hand-designed path to give me complete control over its choreography, while the beetles follow their own stochastically generated paths.
* Camera shake:
* Simple animation-player system:
    - Used for timing the camera shake and the movement of the different centipedes and beetles in this example.
 
#### Design Features
* **Dolly Zoom:** The camera is endlessly dollying towards the mouth of the pit while the field of view increases at an equal but opposite rate. Typically in film this technique is used to convey a sudden sinking feeling, with the zoom being performed rapidly, but I wanted to evoke a feeling of dread and unease as if you're slowly sinking or being pulled into the pit--being pulled so slowly that you can't be sure whether you're actually moving at all; some things appear to be getting closer while others move away. You start to question whether you can trust what you see. You start to understand that wherever you are, it doesn't follow the rules that we're used to--it's otherwordly.
* **Centipede's path:** Hand-designed the large centipede's path in cinematic way--just barely missing the camera and such. As the camera gets pulled closer to the pit and field of view continues to grow, the world starts to wrap around you like light in a black hole. I wanted to convey this feeling of inexplicable attraction, as if the pit has such a powerful intrigue to it that not even light can escape.
* **Anempathetic Audio:** For ambience I've looped a dreamy bell sound. I felt that using a calming and almost hypnotic sound that contrasts with the visuals would convey that you're so drawn to this pit that despite all of the wild things going on in your peripheral you can't help but tune everything out and stare deep into it--almost like you're being mind-controlled or hypnotised by it.
* **Uncanny Lighting:** I used lighting to create a feeling of unease. The lighting in the scene doesn't act realistically: there is no clear lightsource and yet there are strong highlights; there are no shadows being projected; objects which should be in shadow, like the teeth, are bright while other things which should be in the light like the centipede are dark. It may not be wrong enough to be noticable consciously, but I think you can feel that something is off when you look at it even if you're not consciously aware of it. I achieved this by having certain meshes only be influenced their own lightsources, and by baking highlihgts and shadows into textures where possible.
