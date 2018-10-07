{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 34.0, 79.0, 1369.0, 787.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "gain~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 78.0, 45.0, 137.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "jit_matrix", "" ],
					"patching_rect" : [ 30.5, 514.0, 43.0, 22.0 ],
					"style" : "",
					"text" : "jit.add"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "float", "float", "bang" ],
					"patching_rect" : [ 48.5, 120.0, 129.0, 22.0 ],
					"style" : "",
					"text" : "fzero~ @threshold 0.1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-4",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 30.5, 149.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 30.5, 19.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"clipheight" : 45.75,
					"data" : 					{
						"clips" : [ 							{
								"filename" : "/Users/SamSmith/Desktop/school year documents 2018/piano 111/harmonization folder/IMG_0020.TRIM.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
, 							{
								"filename" : "/Users/SamSmith/Desktop/projects in current use/highlights/P1340773.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
, 							{
								"filename" : "/Users/SamSmith/Desktop/projects in current use/highlights/P1330654.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
, 							{
								"filename" : "/Users/SamSmith/Desktop/projects in current use/highlights/P1340187.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
 ]
					}
,
					"id" : "obj-1",
					"maxclass" : "jit.playlist",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "jit_matrix", "", "dictionary" ],
					"patching_rect" : [ 30.5, 311.0, 232.0, 187.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-104",
					"maxclass" : "jit.pwindow",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 30.5, 544.5, 279.0, 209.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-101",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 267.5, 287.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"clipheight" : 45.75,
					"data" : 					{
						"clips" : [ 							{
								"filename" : "/Users/SamSmith/Desktop/school year documents 2018/piano 111/harmonization folder/IMG_0020.TRIM.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
, 							{
								"filename" : "/Users/SamSmith/Desktop/projects in current use/highlights/P1340773.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
, 							{
								"filename" : "/Users/SamSmith/Desktop/projects in current use/highlights/P1330654.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
, 							{
								"filename" : "/Users/SamSmith/Desktop/projects in current use/highlights/P1340187.MOV",
								"filekind" : "moviefile",
								"loop" : 0,
								"content_state" : 								{
									"outputmode" : [ 1 ],
									"out_name" : [ "u405001447" ],
									"dim" : [ 1, 1 ],
									"drawto" : [ "" ],
									"loopend" : [ 0 ],
									"vol" : [ 1.0 ],
									"texture_name" : [ "u357001445" ],
									"adapt" : [ 1 ],
									"unique" : [ 0 ],
									"framereport" : [ 0 ],
									"automatic" : [ 0 ],
									"srcrect" : [ 0, 0, 1, 1 ],
									"looppoints" : [ 0, 0 ],
									"usedstrect" : [ 0 ],
									"time_secs" : [ 0.0 ],
									"autostart" : [ 1 ],
									"output_texture" : [ 0 ],
									"interp" : [ 0 ],
									"usesrcrect" : [ 0 ],
									"loopreport" : [ 0 ],
									"time" : [ 0 ],
									"loopstart" : [ 0 ],
									"dstrect" : [ 0, 0, 1, 1 ],
									"moviefile" : [ "" ],
									"engine" : [ "avf" ],
									"rate" : [ 1.0 ],
									"colormode" : [ "argb" ],
									"position" : [ 0.0 ]
								}

							}
 ]
					}
,
					"id" : "obj-98",
					"maxclass" : "jit.playlist",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "jit_matrix", "", "dictionary" ],
					"patching_rect" : [ 267.5, 311.0, 246.0, 187.0 ],
					"presentation_rect" : [ 436.5, 163.0, 0.0, 0.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-96",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 107.0, 213.0, 33.0, 22.0 ],
					"style" : "",
					"text" : "float"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-95",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 141.0, 179.0, 105.0, 22.0 ],
					"style" : "",
					"text" : "scale 0.05 0.2 1 4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-94",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 30.5, 235.0, 33.0, 22.0 ],
					"style" : "",
					"text" : "float"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 30.5, 206.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 165.5, 153.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-76",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 30.5, 179.0, 99.0, 22.0 ],
					"style" : "",
					"text" : "scale 40 200 1 4"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-72",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 107.0, 153.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 30.5, 45.0, 37.0, 22.0 ],
					"style" : "",
					"text" : "adc~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 78.0, 73.0, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 30.5, 287.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"source" : [ "obj-101", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-5", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-5", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"order" : 1,
					"source" : [ "obj-57", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"order" : 0,
					"source" : [ "obj-57", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-104", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"source" : [ "obj-76", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-94", 0 ],
					"order" : 1,
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"order" : 0,
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 1 ],
					"order" : 0,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"order" : 1,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-94", 1 ],
					"source" : [ "obj-88", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-94", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 1 ],
					"source" : [ "obj-95", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-101", 0 ],
					"source" : [ "obj-96", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 1 ],
					"source" : [ "obj-98", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "IMG_0020.TRIM.MOV",
				"bootpath" : "~/Desktop/school year documents 2018/piano 111/harmonization folder",
				"patcherrelativepath" : "../../../Desktop/school year documents 2018/piano 111/harmonization folder",
				"type" : "MooV",
				"implicit" : 1
			}
, 			{
				"name" : "P1340773.MOV",
				"bootpath" : "~/Desktop/projects in current use/highlights",
				"patcherrelativepath" : "../../../Desktop/projects in current use/highlights",
				"type" : "MooV",
				"implicit" : 1
			}
, 			{
				"name" : "P1330654.MOV",
				"bootpath" : "~/Desktop/projects in current use/highlights",
				"patcherrelativepath" : "../../../Desktop/projects in current use/highlights",
				"type" : "MooV",
				"implicit" : 1
			}
, 			{
				"name" : "P1340187.MOV",
				"bootpath" : "~/Desktop/projects in current use/highlights",
				"patcherrelativepath" : "../../../Desktop/projects in current use/highlights",
				"type" : "MooV",
				"implicit" : 1
			}
, 			{
				"name" : "jit.add.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
