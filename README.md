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
Do[
 SetupSimulation[pressureBC[[i]], "drainBorder" -> "down"];
 Print["pressure BC: ", pressureBC[[i]]];
 tempVector = SolveSimulation[];
 myPressureTotal[[i]] = tempVector[[1]];
 myDisplacementTotal[[i]] = tempVector[[2]];
 displacementMax[[i]] = Min[myDisplacementTotal[[i, All, 2]]];
 pressureMax[[i]] = Max[myPressureTotal[[i, All, 2]]];
 Print[Show[SMTShowMesh["FillElements" -> False, ImageSize -> 400], 
   SMTShowMesh["Field" -> "p", "DeformedMesh" -> True, 
    ImageSize -> 400]], 
  Show[SMTShowMesh["FillElements" -> False, ImageSize -> 400], 
   SMTShowMesh["Field" -> "v", "DeformedMesh" -> True, 
    ImageSize -> 400]]]
 (*If[i==(Length[pressureBC]+1)/2,SMTAnimationOfResponse["Export \
to","mp4","FirstFrame"->"LastFrame","FileName"->"punch_test_null_BC",\
FrameRate->2]];*)
 , {i, 1, Length[pressureBC]}]
```

 ---

 ![](https://github.com/mastroalex/poroelasticity/blob/main/report/figures/punch_frame_2_tex.svg)
 
 ---


- [28 dec](Notebook/first_test/README.md) - Starting `Q1PElin`.
- 03 gen - Finished elasto plastic element after some little advice from the professor. This is in `../Notebook/first_test/` folder.
- 03 feb - Theory and web article
