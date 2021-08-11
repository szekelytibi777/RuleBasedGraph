# RuleBasedGraph
Given a defined graph and a ruleset, the application shall be able to modify original graph.
# rules usable:
## insert
insert subgraph between connected nodes (node1 and node2)

**insert**:{<node1_id>:<node2_id>}{<subgraph descriptor>}
## replace
replace originap subgraph to a new one

**replace**:{<original_subgraph_descriptor>}{<subgraph_descriptor>}	 

## change
change  originap node to a new one

**change**:{<original_node_id>:0}{<changed_node_id>:0}	

## delete
delete subgraph from the graph

**delete**:{<original_subgraph_descriptor_to_delete>}

## add
add subgraph to the graph

**add**:{<node_id>:<node_id>}{<added_subgraph_descriptor>}


