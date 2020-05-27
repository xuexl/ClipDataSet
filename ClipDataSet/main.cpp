
#include<vtkSmartPointer.h>
#include<vtkClipDataSet.h>
#include<vtkPlane.h>
#include<vtkDataSetMapper.h>
#include<vtkPolyDataMapper.h>
#include<vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

#include<vtkSphereSource.h>


int main()
{

    auto sphere = vtkSmartPointer<vtkSphereSource>::New();
    sphere->SetCenter(0,0,0);
    sphere->SetRadius(100);
    sphere->SetPhiResolution(100);
    sphere->SetThetaResolution(100);
    sphere->Update();
    
    auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputConnection(sphere->GetOutputPort());
//    mapper->ScalarVisibilityOff();      //???
    
    auto pm = vtkSmartPointer<vtkPolyDataMapper>::New();
    pm->SetInputConnection(sphere->GetOutputPort());
    
    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(pm);
    
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->SetBackground(0.9, 0.9, 0.9);
    renderer->AddActor(actor);
    
    auto renderWinow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWinow->AddRenderer(renderer);
    
    auto interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(renderWinow);
    
    
    renderWinow->SetSize(1040, 800);
    renderWinow->Render();
    interactor->Start();
    
    
    return 1;
}
