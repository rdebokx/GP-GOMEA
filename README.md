# GP-GOMEA
C++ implementation of the Gene-pool Optimal Mixing Evolutionary Algorithm for Genetic Programming (GP-GOMEA). It also comes with standard tree-based GP, and Semantic Backpropagation-based GP.

GP-GOMEA is especially proficient in finding small and accurate symbolic expressions, to have reliable and interpretable models. Semantic Backpropagation-based GP works well when high accuracy is demanded, at the cost of producing very complex models, which are hard or impossible to interpret. Standard GP is a good baseline to compare the other methods with.

This code also implements the Interlaved Multistart Scheme (IMS), that makes GP more robust w.r.t. setting a specific population size. Setting the population size is tricky: if too small, GP will find models with poor accuracy; If too big, GP will waste computation time. The IMS starts and executes multiple evolutionary runs in an interleaved fashion, with subsequent runs using bigger population sizes. It terminates ongoing runs that perform poorly, according to some heuristics. The IMS is largely inspired from the Parameter-free Genetic Algorithm of Harik and Lobo: https://dl.acm.org/citation.cfm?id=2933949

## Related research work
Coming soon!

## Compilation
Can be compiled on Linux (tested on Ubuntu and Fedora). Use g++ with C++ standard '14 or higher. This code comes as a Netbeans project, which makes compilation and linking easier through an interface. Alternatively, pre-made compilation files are available in the folder `nbproject`. You can change compilation configuration in `nbproject/Makefile-impl.mk`, line 30 (to Debug or Release), then edit `nbproject/Makefile-Release.mk` (or `Makefile-Debug.mk`) to your liking. Finally, call `make`.

### Dependencies
You need the following libraries to use GP-GOMEA:
* Armadillo http://arma.sourceforge.net (see ARMADILLO_NOTICE.txt)
* OpenMP https://www.openmp.org/ (compile using -fopenmp)
* Boost https://www.boost.org/

## Usage
Call `./gp-gomea --help` to get a comprehensive list of parameters. Some parameters are mandatory, some others have defaults. You can set the parameters when calling the executable with `gp-gomea --param1 value1 --param2 value2`; or write them in a parameter file (see the examples for GP-GOMEA, standard GP, and Semantic Backpropagation-based GP), and finally call `./gp-gomea --file param_file.txt`.

### Datasets
You can find supervised learning datasets to play with at: https://goo.gl/9D2z3b 

### Output
The file `stats_generations.txt` contains information that is logged every generation (iteration) of the algorithm. When the run terminates, an output `result.txt` is produced, that also contains the symbolic expression found by GP.

