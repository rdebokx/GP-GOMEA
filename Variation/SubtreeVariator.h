/*
 


 */

/* 
 * File:   SubtreeVariator.h
 * Author: virgolin
 *
 * Created on June 28, 2018, 3:12 PM
 */

#ifndef SUBTREEVARIATOR_H
#define SUBTREEVARIATOR_H

#include "../Genotype/Node.h"
#include "TreeInitializer.h"
#include "../Fitness/Fitness.h"
#include "../Fitness/SymbolicRegressionLinearScalingFitness.h"
#include "../Semantics/SemanticLibrary.h"
#include "../Semantics/SemanticBackpropagator.h"
#include "../Operators/Regression/OpTimes.h"
#include "../Operators/Regression/OpPlus.h"
#include "../Operators/Regression/OpRegrConstant.h"

#include <vector>
#include <armadillo>

class SubtreeVariator {
public:

    SubtreeVariator() {
    };

    static std::pair<Node*, Node*> SubtreeCrossover(const Node & p1, const Node & p2, bool unif_depth_var, bool use_caching);
    static Node * SubtreeMutation(const Node & p, const TreeInitializer & tree_initializer, const std::vector<Operator*> & functions, const std::vector<Operator*> & terminals, size_t initial_max_tree_height, bool unif_depth_var, bool use_caching);
    static Node * TopMutation(const Node & p, const TreeInitializer & tree_initializer, const std::vector<Operator*> & functions, const std::vector<Operator*> & terminals, size_t initial_max_tree_height );
    static Node * SubtreeRDO(const Node& p, int max_height, const arma::mat & X, const arma::vec & Y, SemanticLibrary & semlib, bool unif_depth_var, bool use_caching, bool is_linear_scaling_enabled);
    static std::vector<Node*> GetNodesAtUniformRandomDepth(Node* o, std::vector<Node*>& nodes_o);
    static std::pair<Node*, Node*> SubtreeAGX(Node & p1, Node & p2, int max_height, const arma::mat & X, SemanticLibrary & semlib, bool unif_depth_var, bool use_caching, bool is_linear_scaling_enabled);
    static Node * FindSubtreeForSemanticBackpropagationReplacement(std::vector<arma::vec> & desired_output, SemanticLibrary & semlib, size_t max_h);
    static std::pair<double_t, double_t> GenerateConstantFromDesiredOutput(std::vector<arma::vec> & desired_output, double_t thresh_dist);

private:

};

#endif /* SUBTREEVARIATOR_H */

