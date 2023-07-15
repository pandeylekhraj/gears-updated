[![YouTube](https://img.shields.io/badge/You-Tube-red?style=flat)](https://youtu.be/TSP0RLjhLDw)
[![tutorials](https://img.shields.io/badge/use-GEARS-green?style=flat)](..)
[![visualization](https://img.shields.io/badge/detector-visualization-orange?style=flat)](visualization)
[![boolen](https://img.shields.io/badge/boolean-operation-yellow?style=flat)](boolean)
[![scripts](https://img.shields.io/badge/program-geometry-blue?style=flat)](scripts)
[![optical](https://img.shields.io/badge/optical-properties-cyan?style=flat)](optical)
[![syntax](https://img.shields.io/badge/syntax-highlighting-magenta?style=flat)](syntax)

## Detector construction

### Geometry

Instead of using geometry written in C++ as described in detail in the [Geant4 manual](http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/Detector/Geometry/geomSolids.html), [GEARS][] accepts two types of detector geometry descriptions in pure ASCII format as input:

- Geant4 [text geometry description][tg] (manual: [pdf](https://geant4.web.cern.ch/sites/default/files/geant4/collaboration/working_groups/geometry/docs/textgeom/textgeom.pdf), [html](http://fismed.ciemat.es/GAMOS/GAMOS_doc/GAMOS.6.0.0/Geometry/Geometry.html)) (recommended)
- [GDML][] (provided for data analysis and visualization in other tools)

Their difference is similar to that between [markdown][md] and [HTML][]. The simpler [text geometry description][tg] provided by [Geant4][] is recommended to be used as [GEARS][]'s input given its simplicity and readability. For example, an experimental hall filled with air and of a dimension of 10 x 10 x 10 meters can be easily implemented using the following line:

~~~
:volu hall BOX 5*m 5*m 5*m G4_AIR
~~~

> **Note**
> Please leave a blank line at the end of a `.tg` file, otherwise, Geant4 cannot parse it correctly!

For more examples, please check `*.tg` files in the [tutorials/detector](.) directory, such as [tutorials/detector/gears.tg](gears.tg) and [tutorials/detector/solids.tg](solids.tg). The suffix of *.tg* indicates that they are [text geometry][tg] description files. A [Geant4][] macro command `/geometry/source` is added to load geometry files:

~~~sh
/geometry/source gears.tg
~~~

You can utilize [Boolean operation](boolean) or [shell scripts](scripts) to construct more complicated geometries.

Alternatively, you can read a [GDML][] file:

~~~sh
/geometry/source file.gdml
~~~

The command must be used before [/run/initialize][run], otherwise [GEARS][] will construct a simple experimental hall automatically to prevent crashing.

[GEARS][] provides the following command to export constructed detector geometry to a [GDML][] file:

~~~sh
/geometry/export output.gdml
~~~

This can only be used after the macro command [/run/initialize][run], which constructs the detector geometry before exporting. While the simpler [text geometry description][tg] can only be understood by [Geant4][], [GDML][] can be understood by many other tools. For example, [ROOT][] provides functions to read and visualize [GDML][] geometries. On the other hand, it is not that easy to write a valid [GDML][] file manually. This functionality is provided to enable the following usage:

~~~sh
 # describe the detector using simple text geometry description
 /geometry/source input.tg
 # construct the detector
 /run/intialize
 # export detector geometry as GDML for analysis/visualization in other tools
 /geometry/export output.gdml
~~~

You can find a concrete example in [tutorials/detector/GDML](GDML).

#### Sensitive volume

Total energy deposited in a sensitive volume is recorded in an array in a [GEARS][] [output](../output#total-energy) file. You can turn any volume to a sensitive one by simply adding the string "(S)" at the end of its name. The copy number of the volume is used as the array index to retrieve the total energy deposited in that volume. Note that hits in any volume that has a copy number less than 1 won't be recorded. Consequently, the copy number of a sensitive volume must be larger than 0. If there are multiple sensitive volumes, their copy numbers do not have to be continuous. 

### Material

The [NIST][] material table provided by [Geant4][] contains all elements (C, H, O, for example) and a lot of commonly used materials (start with "G4_"). One can run /material/nist/[listMaterials][] at any [Geant4][] state to print the list locally. These materials can be used directly in a [text geometry description][tg], for example

~~~cpp
// use Geant4 elements, C and H to define TPB
:MIXT_BY_NATOMS TPB 1.079 2 C 28 H 22
// use NIST material G4_AIR to define vacuum
:mixt vacuum 1e-9 1 G4_AIR 1
~~~

To construct more complicated material please refer to the [manual of the text geometry description](http://fismed.ciemat.es/GAMOS/GAMOS_doc/GAMOS.6.0.0/Geometry/Geometry.html).

A color can be assigned to a volume to indicate its material if the geometry is [visualized](visualization). For example, yellow can be assigned to a volume made of copper:

```cpp
:volum stage TUBE 0 20 5 G4_Cu
:color stage 0.85 0.65 0.13
```

The color is defined in the form of rbg(R%, G%, B%), where R, G, and B are the percent values for the red, green, and blue values of the color ranging from 0 to 100. For more color codes, please check <https://johndecember.com/html/spec/colorper.html>.

[GEARS]: http://physino.xyz/gears
[tg]: http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/Detector/Geometry/geomASCII.html
[Geant4]: http://geant4.cern.ch
[NIST]: http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/Appendix/materialNames.html
[run]: http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/Control/AllResources/Control/UIcommands/_run_.html
[listMaterials]: http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/Control/AllResources/Control/UIcommands/_material_nist_.html
[GDML]: https://gdml.web.cern.ch/GDML/
[md]: https://en.wikipedia.org/wiki/Markdown
[HTML]: https://www.w3schools.com/html/
[ROOT]: https://root.cern.ch
