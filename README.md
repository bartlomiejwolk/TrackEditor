# TrackEditor

TrackEditor module for UE4. Use it to create drivable tracks in UE4 editor.

Licensed under MIT license. See LICENSE file in the project root.

![TrackEditor cover screenshot](/Resources/cover_screenshot.png?raw=true "UE4 GraphPlotter module")

Features
--------

- Create drivable tracks in UE4 editor
- You can specify separate meshes for the track base and left/right guard rails

Resources
---
* [Blog Post](???)    
* [Video](???)

Quick Start
------------------

- Clone repository (or extract [zip package](???)) to any location in your project's `Source` folder
- Add _TrackEditor_ module to `.uproject` file
- Add _TrackEditor_ module to your game project  `.Target.cs` file
- Add _TrackEditor_ module to your game module `.build.cs` file
- Create blueprint from the _TrackEditor_ actor class
- Put blueprint actor on the scene
- Specify actor's mobility setting to _Static_
- Specify meshes to be used to build the track
- In the viewport, drag and duplicate spline points to shape the track

Help
-----

Just create an issue and I'll do my best to help.

Contributions
------------

Pull requests, ideas, questions and any feedback at all are welcome.

Versioning
----------

Example: `v0.2.3f1`

- `0` Introduces breaking changes.
- `2` Major release. Adds new features.
- `3` Minor release. Bug fixes and refactoring.
- `f1` Quick fix.

[Semantic Versioning Specification](http://semver.org/)
