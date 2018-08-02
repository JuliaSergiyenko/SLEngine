// Pubic interface
IMGUI_IMPL_API bool ImGui_ImplOpenGLES2_Init();
IMGUI_IMPL_API void ImGui_ImplOpenGLES2_Shutdown();
IMGUI_IMPL_API void ImGui_ImplOpenGLES2_RenderDrawData(ImDrawData* draw_data);

// Called by Init/NewFrame/Shutdown
IMGUI_IMPL_API bool ImGui_ImplOpenGLES2_CreateFontsTexture();
IMGUI_IMPL_API void ImGui_ImplOpenGLES2_DestroyFontsTexture();
IMGUI_IMPL_API bool ImGui_ImplOpenGLES2_CreateDeviceObjects();
IMGUI_IMPL_API void ImGui_ImplOpenGLES2_DestroyDeviceObjects();