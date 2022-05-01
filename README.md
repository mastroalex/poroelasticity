# Multiphysics computational models and poroelasticity 🧽
### Computational Mechanics of Tissues and Biomaterials
### Biomedical Engineering - University of Rome Tor Vergata

#### Abstract

In most phenomena it is often necessary to take into account, in addition to the mechanical characteristics, various other quantities. For example, it is important to analyze the variation over time of quantities such as temperature, thermal flows, current intensity, mass flow, concentration gradients, etc.

Most biological tissues can be seen as porous, permeable and deformable media within which fluids such as blood and interstitial fluid infiltrate. Taking these behaviors into account in a computation model, as with linear poroelasticity, allows to simulate and describe their behavior more precisely. Poroelasticity theories are widely used in civil, petroleum and biomedical engineering. There are several facets of this theory, including models based on Biot's works. The governing equations and the boundary conditions then allow to adapt the computations model to the different environments that can be analyzed.

---

**Read more [website](https://alessandromastrofini.it/en/multiphysic-computational-models/)**

---

```mathematica
 << AceFEM ‘;
SimulationComplete[alpha_ , axialLoad_ , trasLoad_] := (
displacement = Table[{0*i, 0, 0}, {i, 1, Length[alpha]}];
Do[
Print["α=", alpha[[i]]];
MyGeometry[alpha[[i]], axialLoad , trasLoad];
FEMModel [];
Coordinate [];
Solution [];
Print[Show[SMTShowMesh["DeformedMesh" -> True, "Mesh" -> GrayLevel[0.9]], SMTShowMesh["
FillElements" -> False, "BoundaryConditions" -> True, "Mesh" -> GrayLevel[0]]]]; displacement[[i]] = PostProcessMyDisplacement[alpha[[i]]];,
{i, 1, Length[alpha]}];
PrintMyDisplacement[displacement , alpha]; ;
(***)
alpha = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
axLoad = 2*10^3* (L/10);
trLoad = 0.02*10^3;
SimulationComplete[alpha, axLoad, trLoad]
```

 ---

 ![](https://github.com/mastroalex/poroelasticity/blob/main/report/figures/punch_frame_2_tex.svg)
 
 ---


- [28 dec](Notebook/first_test/README.md) - Starting `Q1PElin`.
- 03 gen - Finished elasto plastic element after some little advice from the professor. This is in `../Notebook/first_test/` folder.
- 03 feb - Theory and web article
- 
