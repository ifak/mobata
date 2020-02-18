I-Logix-RPY-Archive version 8.5.2 C++ 1159120
{ IProject 
	- _id = GUID 5161d706-8968-47cc-8b07-ba78ae87f173;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 1;
			- value = 
			{ IPropertySubject 
				- _Name = "CPP_CG";
				- Metaclasses = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Configuration";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "Environment";
								- _Value = "Cygwin";
								- _Type = Enum;
								- _ExtraTypeInfo = "Microsoft,MicrosoftDLL,MSVC9,MSVC9DLL,VxWorks,VxWorks6diab,VxWorks6gnu,VxWorks6diab_RTP,VxWorks6gnu_RTP,Solaris2,Cygwin,MultiWin32,Multi4Win32,MSStandardLibrary,MSVC9StandardLibrary,MicrosoftWinCE600,OseSfk,Linux,Solaris2GNU,QNXNeutrinoGCC, QNXNeutrinoMomentics,INTEGRITY,INTEGRITY5,IntegrityESTL,Integrity5ESTL,NucleusPLUS-PPC,WorkbenchManaged,WorkbenchManaged_RTP";
							}
						}
					}
				}
			}
		}
	}
	- _name = "Project";
	- _lastID = 9;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "Default.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "Default";
		- _id = GUID 96357296-4e78-4107-811b-30ed229d0b8f;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID 0cf94720-1c65-43fc-94ec-fe56e88e69b6;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = 0;
		}
		{ IMultiplicityItem 
			- _name = "*";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "0,1";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "1..*";
			- _count = -1;
		}
	}
	- Subsystems = { IRPYRawContainer 
		- size = 6;
		- value = 
		{ ISubsystem 
			- fileName = "Default";
			- _id = GUID 96357296-4e78-4107-811b-30ed229d0b8f;
		}
		{ ISubsystem 
			- fileName = "ATestPackage";
			- _id = GUID 9726d35d-6659-4c12-9c22-73fef9f7e262;
		}
		{ ISubsystem 
			- fileName = "Event_Collection";
			- _id = GUID 89b676b1-668b-4911-90f0-d456c9f7e35b;
		}
		{ ISubsystem 
			- fileName = "package_4";
			- _id = GUID f00e89bd-cdb1-4458-9ccb-1cd0e8d37a01;
		}
		{ ISubsystem 
			- fileName = "package_5";
			- _id = GUID 19506ea3-974d-4d23-8d71-768b3058a20c;
		}
		{ ISubsystem 
			- fileName = "Design";
			- _id = GUID 0a061b39-84dd-48ff-931a-591527f14839;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 2;
		- value = 
		{ IStructureDiagram 
			- _id = GUID 20172f25-7982-4b94-872f-8629cc0e1a02;
			- _myState = 8192;
			- _name = "Structure1";
			- _lastModifiedTime = "12.11.2017::14:18:22";
			- _graphicChart = { CGIClassChart 
				- _id = GUID 8184f041-2084-4b8b-8250-11706d7ac7c7;
				- m_type = 0;
				- m_pModelObject = { IHandle 
					- _m2Class = "IStructureDiagram";
					- _id = GUID 20172f25-7982-4b94-872f-8629cc0e1a02;
				}
				- m_pParent = ;
				- m_name = { CGIText 
					- m_str = "";
					- m_style = "Arial" 10 0 0 0 1 ;
					- m_color = { IColor 
						- m_fgColor = 0;
						- m_bgColor = 0;
						- m_bgFlag = 0;
					}
					- m_position = 1 0 0  ;
					- m_nIdent = 0;
					- m_bImplicitSetRectPoints = 0;
					- m_nOrientationCtrlPt = 8;
				}
				- m_drawBehavior = 0;
				- m_bIsPreferencesInitialized = 0;
				- elementList = 1;
				{ CGIClass 
					- _id = GUID cde10601-7101-4374-9c98-4179b6fe60d2;
					- m_type = 78;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "Default.sbs";
						- _subsystem = "Default";
						- _class = "";
						- _name = "TopLevel";
						- _id = GUID ff121501-b57d-4a45-a778-4acadb675ac7;
					}
					- m_pParent = ;
					- m_name = { CGIText 
						- m_str = "TopLevel";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 5;
					}
					- m_drawBehavior = 0;
					- m_bIsPreferencesInitialized = 0;
					- m_AdditionalLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 1;
					}
					- m_polygon = 0 ;
					- m_nNameFormat = 0;
					- m_nIsNameFormat = 0;
					- Attrs = { IRPYRawContainer 
						- size = 0;
					}
					- Operations = { IRPYRawContainer 
						- size = 0;
					}
				}
				
				- m_access = 'Z';
				- m_modified = 'N';
				- m_fileVersion = "";
				- m_nModifyDate = 0;
				- m_nCreateDate = 0;
				- m_creator = "";
				- m_bScaleWithZoom = 1;
				- m_arrowStyle = 'S';
				- m_pRoot = GUID cde10601-7101-4374-9c98-4179b6fe60d2;
				- m_currentLeftTop = 0 0 ;
				- m_currentRightBottom = 0 0 ;
			}
			- _defaultSubsystem = { IHandle 
				- _m2Class = "ISubsystem";
				- _filename = "Default.sbs";
				- _subsystem = "";
				- _class = "";
				- _name = "Default";
				- _id = GUID 96357296-4e78-4107-811b-30ed229d0b8f;
			}
		}
		{ IDiagram 
			- _id = GUID 297a55f6-4df3-4579-8801-ba1f1c0978e3;
			- _myState = 10240;
			- _properties = { IPropertyContainer 
				- Subjects = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertySubject 
						- _Name = "Format";
						- Metaclasses = { IRPYRawContainer 
							- size = 4;
							- value = 
							{ IPropertyMetaclass 
								- _Name = "Class";
								- Properties = { IRPYRawContainer 
									- size = 8;
									- value = 
									{ IProperty 
										- _Name = "DefaultSize";
										- _Value = "0,34,84,148";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Fill.FillColor";
										- _Value = "255,255,255";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Font";
										- _Value = "Arial";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Font.FontColor";
										- _Value = "0,0,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Size";
										- _Value = "10";
										- _Type = Int;
									}
									{ IProperty 
										- _Name = "Line.LineColor";
										- _Value = "121,122,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Line.LineStyle";
										- _Value = "0";
										- _Type = Int;
									}
									{ IProperty 
										- _Name = "Line.LineWidth";
										- _Value = "1";
										- _Type = Int;
									}
								}
							}
							{ IPropertyMetaclass 
								- _Name = "Object";
								- Properties = { IRPYRawContainer 
									- size = 9;
									- value = 
									{ IProperty 
										- _Name = "DefaultSize";
										- _Value = "0,34,84,148";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Fill.FillColor";
										- _Value = "255,255,255";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Font";
										- _Value = "Arial";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Font.FontColor";
										- _Value = "0,0,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Size";
										- _Value = "10";
										- _Type = Int;
									}
									{ IProperty 
										- _Name = "Font.Underline@Child.NameCompartment@Name";
										- _Value = "1";
										- _Type = Int;
									}
									{ IProperty 
										- _Name = "Line.LineColor";
										- _Value = "121,122,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Line.LineStyle";
										- _Value = "0";
										- _Type = Int;
									}
									{ IProperty 
										- _Name = "Line.LineWidth";
										- _Value = "1";
										- _Type = Int;
									}
								}
							}
							{ IPropertyMetaclass 
								- _Name = "Package";
								- Properties = { IRPYRawContainer 
									- size = 7;
									- value = 
									{ IProperty 
										- _Name = "DefaultSize";
										- _Value = "0,0,216,151";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Fill.FillColor";
										- _Value = "255,255,255";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Font";
										- _Value = "Arial";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Font.FontColor";
										- _Value = "0,0,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Size";
										- _Value = "10";
										- _Type = Int;
									}
									{ IProperty 
										- _Name = "Line.LineColor";
										- _Value = "221,0,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Line.LineWidth";
										- _Value = "1";
										- _Type = Int;
									}
								}
							}
							{ IPropertyMetaclass 
								- _Name = "Port";
								- Properties = { IRPYRawContainer 
									- size = 7;
									- value = 
									{ IProperty 
										- _Name = "DefaultSize";
										- _Value = "0,0,68,73";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Fill.FillColor";
										- _Value = "255,255,255";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Font";
										- _Value = "Arial";
										- _Type = String;
									}
									{ IProperty 
										- _Name = "Font.FontColor";
										- _Value = "0,0,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Font.Size";
										- _Value = "10";
										- _Type = Int;
									}
									{ IProperty 
										- _Name = "Line.LineColor";
										- _Value = "121,122,0";
										- _Type = Color;
									}
									{ IProperty 
										- _Name = "Line.LineWidth";
										- _Value = "1";
										- _Type = Int;
									}
								}
							}
						}
					}
				}
			}
			- _name = "objectmodeldiagram_7";
			- _lastModifiedTime = "12.12.2017::12:53:6";
			- _graphicChart = { CGIClassChart 
				- _id = GUID b3e16a05-3fed-4365-8bdd-24b20517886f;
				- m_type = 0;
				- m_pModelObject = { IHandle 
					- _m2Class = "IDiagram";
					- _id = GUID 297a55f6-4df3-4579-8801-ba1f1c0978e3;
				}
				- m_pParent = ;
				- m_name = { CGIText 
					- m_str = "";
					- m_style = "Arial" 10 0 0 0 1 ;
					- m_color = { IColor 
						- m_fgColor = 0;
						- m_bgColor = 0;
						- m_bgFlag = 0;
					}
					- m_position = 1 0 0  ;
					- m_nIdent = 0;
					- m_bImplicitSetRectPoints = 0;
					- m_nOrientationCtrlPt = 8;
				}
				- m_drawBehavior = 0;
				- m_bIsPreferencesInitialized = 0;
				- elementList = 7;
				{ CGIClass 
					- _id = GUID a5d529c5-e428-47b6-9bf8-d5d35630cd83;
					- m_type = 78;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "Default.sbs";
						- _subsystem = "Default";
						- _class = "";
						- _name = "TopLevel";
						- _id = GUID ff121501-b57d-4a45-a778-4acadb675ac7;
					}
					- m_pParent = ;
					- m_name = { CGIText 
						- m_str = "TopLevel";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 5;
					}
					- m_drawBehavior = 0;
					- m_bIsPreferencesInitialized = 0;
					- m_AdditionalLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 1;
					}
					- m_polygon = 0 ;
					- m_nNameFormat = 0;
					- m_nIsNameFormat = 0;
					- Attrs = { IRPYRawContainer 
						- size = 0;
					}
					- Operations = { IRPYRawContainer 
						- size = 0;
					}
				}
				{ CGIClass 
					- _id = GUID 2b02511f-000c-4d2e-8f47-f764f813af78;
					- m_type = 87;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "SubPackage.sbs";
						- _subsystem = "Design::SubPackage";
						- _class = "Test";
						- _name = "class_2";
						- _id = GUID 60d150e7-b72e-443b-920f-524ad8b041ac;
					}
					- m_pParent = GUID a5d529c5-e428-47b6-9bf8-d5d35630cd83;
					- m_name = { CGIText 
						- m_str = "Design::SubPackage::Test::class_2";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 5;
					}
					- m_drawBehavior = 2056;
					- m_transform = 0.0793201 0 0 0.101604 497.841 463.572 ;
					- m_bIsPreferencesInitialized = 1;
					- m_AdditionalLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 1;
					}
					- m_polygon = 4 2 329  2 1451  1061 1451  1061 329  ;
					- m_nNameFormat = 0;
					- m_nIsNameFormat = 0;
					- frameset = "<frameset rows=50%,50%>
<frame name=AttributeListCompartment>
<frame name=PrimitiveOperationListCompartment>";
					- Attrs = { IRPYRawContainer 
						- size = 0;
					}
					- Operations = { IRPYRawContainer 
						- size = 0;
					}
				}
				{ CGIClass 
					- _id = GUID e88a66c9-bd86-4b1f-9f29-e6fdf3fb7014;
					- m_type = 87;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "SubPackage.sbs";
						- _subsystem = "Design::SubPackage";
						- _class = "AnotherWrongClass";
						- _name = "class_3";
						- _id = GUID b08f5aa4-745d-4f79-8612-c3adc7502b9c;
					}
					- m_pParent = GUID a5d529c5-e428-47b6-9bf8-d5d35630cd83;
					- m_name = { CGIText 
						- m_str = "Design::SubPackage::AnotherWrongClass::class_3";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 5;
					}
					- m_drawBehavior = 2056;
					- m_transform = 0.0793201 0 0 0.101604 817.841 508.572 ;
					- m_bIsPreferencesInitialized = 1;
					- m_AdditionalLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 1;
					}
					- m_polygon = 4 2 329  2 1451  1061 1451  1061 329  ;
					- m_nNameFormat = 0;
					- m_nIsNameFormat = 0;
					- frameset = "<frameset rows=50%,50%>
<frame name=AttributeListCompartment>
<frame name=PrimitiveOperationListCompartment>";
					- Attrs = { IRPYRawContainer 
						- size = 0;
					}
					- Operations = { IRPYRawContainer 
						- size = 0;
					}
				}
				{ CGIPortConnector 
					- _id = GUID 353ee6db-371b-4de2-896e-8d817115d233;
					- m_type = 57;
					- m_pModelObject = { IHandle 
						- _m2Class = "IPort";
						- _filename = "SubPackage.sbs";
						- _subsystem = "Design::SubPackage";
						- _class = "Test::class_2";
						- _name = "port_0";
						- _id = GUID 7df0eea8-8c76-4b9f-9f2a-edfec2acf1d5;
					}
					- m_pParent = GUID 2b02511f-000c-4d2e-8f47-f764f813af78;
					- m_name = { CGIText 
						- m_str = "port_0";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nVerticalSpacing = -19;
						- m_nOrientationCtrlPt = 0;
					}
					- m_drawBehavior = 4104;
					- m_transform = 0 9.84211 -12.6071 0 1556.07 657.86 ;
					- m_bIsPreferencesInitialized = 1;
					- m_position = 4 0 0  0 73  68 73  68 0  ;
					- m_pInheritsFrom = { IHandle 
						- _m2Class = "";
					}
					- m_nInheritanceMask = 0;
					- m_SubType = 0;
					- m_providedInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = 67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
					- m_requiredInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = -67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
				}
				{ CGIPortConnector 
					- _id = GUID c1a37df5-5e38-4274-afcd-44c26f69c786;
					- m_type = 57;
					- m_pModelObject = { IHandle 
						- _m2Class = "IPort";
						- _filename = "SubPackage.sbs";
						- _subsystem = "Design::SubPackage";
						- _class = "AnotherWrongClass::class_3";
						- _name = "port_0";
						- _id = GUID 18b808f4-a841-4a54-b055-bf1ee29e6304;
					}
					- m_pParent = GUID e88a66c9-bd86-4b1f-9f29-e6fdf3fb7014;
					- m_name = { CGIText 
						- m_str = "port_0";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nVerticalSpacing = -19;
						- m_nOrientationCtrlPt = 2;
					}
					- m_drawBehavior = 4104;
					- m_transform = -4.19305e-005 -9.84211 12.6071 -3.27342e-005 -497.07 1202.3 ;
					- m_bIsPreferencesInitialized = 1;
					- m_position = 4 0 0  0 73  68 73  68 0  ;
					- m_pInheritsFrom = { IHandle 
						- _m2Class = "";
					}
					- m_nInheritanceMask = 0;
					- m_SubType = 0;
					- m_providedInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = 67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
					- m_requiredInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = -67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
				}
				{ CGIPortConnector 
					- _id = GUID d6fc9205-20ee-4c8b-9019-22a40140298a;
					- m_type = 57;
					- m_pModelObject = { IHandle 
						- _m2Class = "IPort";
						- _filename = "SubPackage.sbs";
						- _subsystem = "Design::SubPackage";
						- _class = "Test::class_2";
						- _name = "port_1";
						- _id = GUID 0a889fe4-5a1d-452f-bb9a-f041acd66f5d;
					}
					- m_pParent = GUID 2b02511f-000c-4d2e-8f47-f764f813af78;
					- m_name = { CGIText 
						- m_str = "port_1";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nVerticalSpacing = -19;
						- m_nOrientationCtrlPt = 0;
					}
					- m_drawBehavior = 4104;
					- m_transform = 0 9.84211 -12.6071 0 1556.07 1031.86 ;
					- m_bIsPreferencesInitialized = 1;
					- m_position = 4 0 0  0 73  68 73  68 0  ;
					- m_pInheritsFrom = { IHandle 
						- _m2Class = "";
					}
					- m_nInheritanceMask = 0;
					- m_SubType = 0;
					- m_providedInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = 67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
					- m_requiredInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = -67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
				}
				{ CGIPortConnector 
					- _id = GUID 13f824ab-c52e-4cec-aa6b-a74d99fcb1be;
					- m_type = 57;
					- m_pModelObject = { IHandle 
						- _m2Class = "IPort";
						- _filename = "SubPackage.sbs";
						- _subsystem = "Design::SubPackage";
						- _class = "Test::class_2";
						- _name = "port_2";
						- _id = GUID 4e1df4ea-5737-4afd-bec0-2e2ad81c8c22;
					}
					- m_pParent = GUID 2b02511f-000c-4d2e-8f47-f764f813af78;
					- m_name = { CGIText 
						- m_str = "port_2";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = -27;
						- m_nVerticalSpacing = 9;
						- m_nOrientationCtrlPt = 1;
					}
					- m_drawBehavior = 4104;
					- m_transform = -12.6071 0 -0 -9.84211 783.643 1834.84 ;
					- m_bIsPreferencesInitialized = 1;
					- m_position = 4 0 0  0 73  68 73  68 0  ;
					- m_pInheritsFrom = { IHandle 
						- _m2Class = "";
					}
					- m_nInheritanceMask = 0;
					- m_SubType = 0;
					- m_providedInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = 67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
					- m_requiredInterfaceLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nHorizontalSpacing = -67;
						- m_nVerticalSpacing = -25;
						- m_nOrientationCtrlPt = 8;
					}
				}
				
				- m_access = 'Z';
				- m_modified = 'N';
				- m_fileVersion = "";
				- m_nModifyDate = 0;
				- m_nCreateDate = 0;
				- m_creator = "";
				- m_bScaleWithZoom = 1;
				- m_arrowStyle = 'S';
				- m_pRoot = GUID a5d529c5-e428-47b6-9bf8-d5d35630cd83;
				- m_currentLeftTop = 0 0 ;
				- m_currentRightBottom = 0 0 ;
			}
			- _defaultSubsystem = { IHandle 
				- _m2Class = "ISubsystem";
				- _filename = "Default.sbs";
				- _subsystem = "";
				- _class = "";
				- _name = "Default";
				- _id = GUID 96357296-4e78-4107-811b-30ed229d0b8f;
			}
		}
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID 0cf94720-1c65-43fc-94ec-fe56e88e69b6;
		}
	}
}

