# RuleBasedGraph
Given a defined graph and a ruleset, the application shall be able to modify original graph.

Developed in a docker environment, the source code is compiled with the latest version of gcc
This application uses graphwiz next to x terminal for visual representation:
### executable use:
**main** _<graph_descriptor_file_path> <modifier_rules_file_path>

### example content of the graph descriptor file: _(mms sample graph)_

<div style='background: lightgreen; padding: 10px 15px; line-height'> 
in1:a
in2:d
a:b
b:c
c:f
d:e
e:f
f:g,h
h:j
g:i,j
i:l,k
k:out1
l:out2
j:out3
</div>

### example content of the modifier rules file: _(mms sample graph)_

<div style='background: lightgreen; padding: 10px 15px; line-height'> 
delete:{a:b;b:c}
insert:{in1:f}{x:x}
insert:{d:e}{y:y}
delete:{f:h,g;h:i;g:i,j;i:k,l;k:out1;l:out2;j:out3}
add:{x:0}{z:v;v:out1}
add:{z:0}{w:out2,out3}
edge:{e:z}
</div>


##### subgraph descriptor
{<start_node>:<comma_separated_list_of_end_nodes>}
"0" node_id in a subgraph means that node is null in the implementation
# rules usable:
## add
add subgraph to the graph:
modifier subgraph can be started from an existing node in the graph
or can be ends on an allready existing node

**add** :{<existing_node_started_from>:<existing_node_ends_with>}{<modifier_subgraph>}

## insert
insert subgraph between connected nodes (node1 and node2)

**insert**:{<node1_id>:<node2_id>}{<subgraph descriptor>}

## delete
delete subgraph from the graph

**delete**:{<descriptor_of_original_subgraph_to_delete>}

##  edge
connect two nodes in the graph

**edge**:{<from_node_id>:<to_node_id>}





